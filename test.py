import nbioapi

FIR_ONE = 'AQAAABQAAAAkAQAAAQASAAEAZAAAAAAAGAEAACibQEbKj7kM4ohBVA*s7zD8fMlbCegJzQ6b*1z3Bn0Hi6EMCFZgjLwBZgozfLXiarCMv5HNljEWEn9J9aaohX7Ca3WjrKhK3jdKiWH*sEU/W5tYxMRiBMrHv6gckxXTUQiSzj0HfY9YAuIRGWMoAug76k/zy4*sd2jy6CTG9HKety2y5xHi1D1YRXCB86etin0rI7yX7a7xH76RF2qclprW0fecsDB3rEOHT*DaUiHXF5qGYy34k04iuoPAZUPCYHZrE3Y4UH1c9XaIcS2Pc26y20BZoOHIuPrb/1OSwobn9aqICE84488R*Bd0LuaPtG8/ETXT5KPtWWsiVaG6dvjuFbvcwAvlAF1vwH/*GhalJenYePSmR0FFhdDrf5zPIw'
FIR_TWO = 'AQAAABQAAAAUAQAAAQASAAEAZAAAAAAAEAEAAERHn6O5yuXgWDPXc3l7guL2nuRLPR1grUSvdFCAhJapX/tuzycdgAj6mGx0hTIsnfWza9Wg/TJfnjrLo7L4Q*AmOqj37n08s25putjQjtQnWskwkcfD2i6h3kscBd6OK/5cSx/X39t6YbFzIGPPB859lf4E/oby3Ybw40GMt*qCWGhWDl2nhSh6N4QrjdDmtuSwnBUgPQt8mf*tlEzlE74e1OJ/USabzdNI/v4bV9hK/CTrScZT*9hdRLbPaN/x6g3aXNwfWrp1EZ*dKLEe6ibaYOgS/5CRqJwIa4msBDebtzYGTkGJdPW07RpezUnJ9YnEJEhrgjXFFMsD931KPLcDfXuE*Za1duL1CdfpRwMP'

if __name__ == '__main__':
    nbioapi.init()
    if nbioapi.match(FIR_ONE, FIR_TWO):
        print 'Matching!!!'
    else:
        print 'No Matching!!!'
    nbioapi.terminate()
