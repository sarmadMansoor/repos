def costFunction(X, Y, m, c):
    count = len(X)
    total_error = 0
    for i in range(count):
        total_error += (((m * X[i]) + c) - Y[i]) ** 2
    return total_error / count  # Mean Squared Error


def derivativeOfThetaNot(X, Y, m, c):
    count = len(X)
    total_error = 0
    for i in range(count):
        total_error += (((m * X[i]) + c) - Y[i])
    return total_error / count


def derivativeOfThetaOne(X, Y, m, c):
    count = len(X)
    total_error = 0
    for i in range(count):
        total_error += ((((m * X[i]) + c) - Y[i]) * X[i])
    return total_error / count


def gradient_descent(X, y, learning_rate=0.01, tolerance=0.000001):
    theta_not = 0
    theta_one = 0

    while True:
        # Calculate gradients
        gradient_theta_not = derivativeOfThetaNot(X, y, theta_one, theta_not)
        gradient_theta_one = derivativeOfThetaOne(X, y, theta_one, theta_not)

        # Save old values before updating
        old_theta_not = theta_not
        old_theta_one = theta_one

        # Update theta values
        theta_not -= learning_rate * gradient_theta_not
        theta_one -= learning_rate * gradient_theta_one

        # Check for convergence
        if abs(theta_not - old_theta_not) < tolerance and abs(theta_one - old_theta_one) < tolerance:
            print("Convergence reached.")
            break

    return theta_not, theta_one


def calculate_cost_at_min_theta(X, Y, theta_one, theta_not):
    return costFunction(X, Y, theta_one, theta_not)


# Example usage
X = [1, 2, 3, 4, 5]
y = [2, 4, 5, 4, 5]

# Perform gradient descent to find optimized theta values
theta_not, theta_one = gradient_descent(X, y)

# Calculate cost at minimum theta values
cost_at_min_theta = calculate_cost_at_min_theta(X, y, theta_one, theta_not)

print("theta_not:", theta_not)
print("theta_one:", theta_one)
print("Cost at minimum theta values:", cost_at_min_theta)
