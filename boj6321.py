n = input() 
for i in range(1,n+1): 
	s = raw_input() # take input as string, also python strings are immutable 
	t = "" 
	for j in range(0,len(s)):  
		if s[j] == 'Z': 	
			t += 'A'; 
		else:  
			t += chr(ord(s[j])+1) 
	print "String #%d" %(i) 
	print t 
	print 

