from __future__ import print_function
t = input()
t = int(t)
while t:
	t = t-1
	s = input()
	s = s.split('.')
	for i in range(len(s)):
		print(s[len(s)-i-1],end='')
		if(i!=len(s)-1):
			print(".",end='')
	print("",end='\n')