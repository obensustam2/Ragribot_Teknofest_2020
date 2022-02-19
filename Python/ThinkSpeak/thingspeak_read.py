import requests
import json

def thingspeak_read() :
    URL='https://api.thingspeak.com/channels/1035281/fields/1.json?api_key='    #1024833
    KEY='RYBH9Z20NMPIKKMJ'  #P1IVLK79FD8FMIBE
    HEADER='&results=1'
    NEW_URL=URL+KEY+HEADER
    print(NEW_URL)

    get_data=requests.get(NEW_URL).json()
    print(get_data)
    a=get_data['feeds'][0]
    print(a)
    b = list(a.values())[-1]
    print(b)

if __name__ == '__main__' :
    thingspeak_read()