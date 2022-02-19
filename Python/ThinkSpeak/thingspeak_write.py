import urllib.request

def thingspeak_post() :
    URL = 'https://api.thingspeak.com/update?api_key='
    KEY = 'MAVC087S1HVCXGIJ'
    HEADER = '&field1={}'.format(6)
    NEW_URL = URL + KEY + HEADER
    data= urllib.request.urlopen(NEW_URL)
    print(data)

if __name__ == '__main__' :
    thingspeak_post()