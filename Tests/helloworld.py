#!/usr/bin/env python2

def helloworld():
    print "Hello world !"
    
def bonjourlemonde():
    print "Bonjour le monde !"
       
def hello_i18n(language):
    lang = {"en": helloworld, "fr": bonjourlemonde}
    if language not in lang.keys():
        return lang[en]()
    else:
        return lang[language]()
