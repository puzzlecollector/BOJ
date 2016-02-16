#  @:x3,  %:+5, #:-7 
t = int(input()) 
for k in range(0,t): 
	p = raw_input()
	p = p.split() 
	num = 0 
	for i in p: 
		if i == '@':
			num *= 3.00 
		elif i == '%':
			num += 5.00 
		elif i == '#': 
			num -= 7.00 
		else:
			num += float(i) 
	print "%.2f"%num 
