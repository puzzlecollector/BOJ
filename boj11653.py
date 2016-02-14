import math

x = int(input())
until = int(math.sqrt(x)+1)
for i in range(2,until):
	while (x%i == 0): 
		print i
		#print '\n'
		x /= i 
if x != 1: 
	print x
	#print '\n'
