def myMSE(X,Y,m,c):
    n=len(X);
    totalError=0;
    for i in range(n):
        pred_Y=m*X[i]+c;
        totalError+=(Y[i]-pred_Y)**2
    mse=totalError/n;
    return mse;

#X = [1, 2, 3]
#Y = [2, 4, 6]
#m = 2
#c = 0


def myMSE2(X, Y, m, C):
    costs = []  # List to hold the costs for each intercept
    
    # Loop through each intercept in C
    for c in C:
        totalError = 0  # Initialize total error for the current intercept
        n = len(X)  # Number of data points
        
        # Loop through each data point
        for i in range(n):
            pred_Y = m * X[i] + c  # Calculate predicted Y using the current intercept
            totalError += (Y[i] - pred_Y) ** 2  # Add squared difference to total error
        
        # Calculate mean squared error for this intercept
        mse = totalError / n
        costs.append(mse)  # Store the cost
    
    return costs  # Return list of costs for each intercept


def getMin2(X,Y,m,C):
    cost =myMSE2(X,Y,m,C);
    return min(cost)
   
    
def myMSE3(X, Y, M, C):
    costs = []  # List to hold the costs for each combination of m and c
    
    # Loop through each slope in M
    for m in M:
        # Loop through each intercept in C
        for c in C:
            totalError = 0  # Initialize total error for the current combination
            n = len(X)  # Number of data points
            
            # Loop through each data point
            for i in range(n):
                pred_Y = m * X[i] + c  # Calculate predicted Y using the current m and c
                totalError += (Y[i] - pred_Y) ** 2  # Add squared difference to total error
            
            # Calculate mean squared error for this combination
            mse = totalError / n
            costs.append(mse)  # Store the cost
    
    return costs  # Return list of costs for each combination

def getMin3(X,Y,M,C):
    cost =myMSE3(X,Y,M,C);
    return min(cost)
# Example usage
X = [1, 2, 3]
Y = [2, 4, 6]
M = [1, 2, 3]  # Different slopes to evaluate
C = [0, 1, 2]  # Different intercepts to evaluate

print(myMSE3(X, Y, M, C))  # Returns costs for each combination of m and c
print(getMin3(X,Y,M,C))
'''
# Example usage
X = [1, 2, 3]
Y = [2, 4, 6]
m = 2
C = [0, 1, 2]  # Different intercepts to evaluate

print(myMSE2(X, Y, m, C))  # Returns costs for each combination of m and c

print(getMin2(X, Y, m, C))
#print(myMSE(X, Y, m, c))  # Should return 0 since this is a perfect fit'''

