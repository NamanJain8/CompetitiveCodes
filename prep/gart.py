import numpy as np
X = np.asarray([[1,0],[0,1],[1,2],[1,1]])

x,y = X.shape

X_new = np.empty(shape=(x,0))
for i in range(y):
	maxi = np.max(X[:,i])
	temp = np.zeros((x,maxi))
	for j in range(x):
		if X[j][i] != 0:
			temp[j][X[j][i]-1] = 1
	# print temp
	X_new = np.concatenate((X_new,temp),axis=1)
# print X
print X_new