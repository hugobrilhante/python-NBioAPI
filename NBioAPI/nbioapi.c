#include <Python.h>
#include "nbioapi.h"

static PyObject *nbioapi_init(PyObject *self) {

    apiReturn = NBioAPI_Init(&apiHandle);

    if (apiReturn != NBioAPIERROR_NONE) {
        return PyErr_Format(PyExc_RuntimeError, "Cannot initialize Nitgen API");
    }

    Py_RETURN_TRUE;
}

static PyObject *nbioapi_terminate(PyObject *self) {

    NBioAPI_Terminate(apiHandle);

    Py_RETURN_NONE;

}

static PyObject *nbioapi_match(PyObject *self, PyObject *args) {

    char *firClient, *firServer;

    if (!PyArg_ParseTuple(args, "ss", &firClient, &firServer)) {
        return PyErr_Format(PyExc_RuntimeError, "Invalid arguments");
    }

    NBioAPI_BOOL apiBool;
    NBioAPI_INPUT_FIR inputFIRServer, inputFIRClient;
    NBioAPI_FIR_TEXTENCODE apiFirTextencodeServer, apiFirTextencodeClient;

    size_t lengthServer = (int) strlen(firServer) + 1;
    size_t lengthClient = (int) strlen(firClient) + 1;

    NBioAPI_CHAR server[lengthServer];
    NBioAPI_CHAR client[lengthClient];

    apiFirTextencodeServer.IsWideChar = NBioAPI_FALSE;
    apiFirTextencodeServer.TextFIR = server;
    memcpy(apiFirTextencodeServer.TextFIR, firServer, lengthServer);

    apiFirTextencodeClient.IsWideChar = NBioAPI_FALSE;
    apiFirTextencodeClient.TextFIR = client;
    memcpy(apiFirTextencodeClient.TextFIR, firClient, lengthClient);


    inputFIRServer.Form = NBioAPI_FIR_FORM_TEXTENCODE;
    inputFIRServer.InputFIR.TextFIR = &apiFirTextencodeServer;

    inputFIRClient.Form = NBioAPI_FIR_FORM_TEXTENCODE;
    inputFIRClient.InputFIR.TextFIR = &apiFirTextencodeClient;

    apiReturn = NBioAPI_VerifyMatch(
            apiHandle,
            &inputFIRServer,
            &inputFIRClient,
            &apiBool,
            NULL
    );

    if (apiReturn != NBioAPIERROR_NONE) {
        switch (apiReturn) {
            case NBioAPIERROR_INVALID_HANDLE:
                return PyErr_Format(PyExc_RuntimeError, "Invalid handle");
            case NBioAPIERROR_INVALID_POINTER:
                return PyErr_Format(PyExc_RuntimeError, "Invalid pointer");
            case NBioAPIERROR_ENCRYPTED_DATA_ERROR:
                return PyErr_Format(PyExc_RuntimeError, "Encrypted data error");
            case NBioAPIERROR_INTERNAL_CHECKSUM_FAIL:
                return PyErr_Format(PyExc_RuntimeError, "Checksum fail");
            case NBioAPIERROR_MUST_BE_PROCESSED_DATA:
                return PyErr_Format(PyExc_RuntimeError, "Must be processed data");
            default:
                return PyErr_Format(PyExc_RuntimeError, "Unknown reason");
        }
    }


    if (apiBool == NBioAPI_TRUE) {
        Py_RETURN_TRUE;
    }

    Py_RETURN_FALSE;


}

static PyMethodDef NBioAPIMethods[] = {
        {"init",      (PyCFunction) nbioapi_init, METH_NOARGS,  "Init module"},
        {"terminate", nbioapi_terminate,          METH_NOARGS, "Terminate module"},
        {"match",     nbioapi_match,              METH_VARARGS, "Match fir"},
        {NULL, NULL,                              0, NULL}
};

PyMODINIT_FUNC initnbioapi(void) {
    Py_InitModule("nbioapi", NBioAPIMethods);
}
