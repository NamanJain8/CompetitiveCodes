t = input()
t=int(t)
while t:
	t = t-1
	s=input()
	s=s.split('.')
	for i in range(len(s)):
		print(s[len(s)-i-1],end='.')