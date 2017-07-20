#!/usr/bin/env python
# coding: utf-8

from distutils.core import setup, Extension

setup(
    name='nbioapi',
    version='1.0.0',
    author='Hugo Brilhante',
    author_email='hugobrilhante@gmail.com',
    license='MIT',
    description='The Client/Server Environment',
    url='https://github.com/hugobrilhante/python-NBioAPI',
    classifiers=[
        'Intended Audience :: Developers',
        'Operating System :: Linux',
        'Topic :: Software Development',
        'Programming Language :: Python :: 2.7',
    ],
    ext_modules=[
        Extension("nbioapi",
                  sources=["NBioAPI/nbioapi.c"],
                  libraries=['NBioBSP'],
                  include_dirs=["/usr/local/NITGEN/eNBSP/include"])
    ]
)
