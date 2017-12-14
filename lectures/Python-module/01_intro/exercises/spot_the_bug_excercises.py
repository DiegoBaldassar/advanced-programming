
def spot_the_bug1():
    def define_methods():
        methods = []                       
        for i in range(10):                        
            methods.append(lambda var: 2*var + i )        
        return methods
    ########################
    # corrected fun here
    ########################
    def define_methods():
        return [lambda var, i=i: 2*var + i for i in range(10)]

    funs = define_methods()
    for i,f in enumerate(funs): 
        assert f(5)==2*5+i, 'why f(5) is '+str(f(5))+' instead of '+str(10+i)+'?'
        print('f(5) ==',f(5),'== 2*5+i ==',(2*5+i))


def spot_the_bug2():
    def append_u_words(words, return_list=[]): # 'u' should be added to return_list when provided
        u_words = [word for word in words if word.startswith('u')]
        return_list += u_words
        return return_list
    ########################
    # corrected fun here
    ########################
    def append_u_words(words, return_list=[]): # 'u' should be added to return_list when provided
        return return_list + [word for word in words if word.startswith('u')]
    
    assert append_u_words(["u_word", "not_u_word"])          == ['u_word']       , 'wrong word list - 1'
    assert append_u_words(["u_word", "not_u_word"],["word"]) == ['word','u_word'], 'wrong word list - 2'
    assert append_u_words(["under_control", "whatever"])     == ["under_control"], 'wrong word list - 3'
    assert append_u_words(["under_control", "whatever"],[])  == ["under_control"], 'wrong word list - 4'
    assert append_u_words(["unbelievable"])                  == ["unbelievable"] , 'wrong word list - 5'
     

if __name__ == '__main__': 
    
    tests = [\
             'spot_the_bug1()',\
             'spot_the_bug2()',\
            ]
    for t in tests:
        try:
            print(t,end='\n->\n')
            print(eval(t))
            print('~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~')
        except AssertionError as err:
            print("ERROR: ",err) 
    
