# copy from https://github.com/andrewdalpino/ml-cheatsheet/blob/master/code/nn_simple.py

import math
import numpy as np

def relu(z):
	return max(0, z)

def forward(x, Wh, Wo):
	# Hidden layer
	Zh = x * Wh
	H = relu(Zh)

	# Output layer
	Zo = H * Wo
	output = relu(Zo)
	return output

def relu_prime(z):
	if z > 0:
		return 1
	return 0
	
def cost(yHat, y):
	return 0.5 * (yHat - y)**2
	
def cost_prime(yHat, y):
	return yHat - y

def backprop(x, y, Wh, Wo, lr, Zo, Zh, H, X):
	yHat = forward(x, Wh, Wo)
	# Layer error
	Eo = (yHat - y)*relu_prime(Zo)
	Eh = Eo * Wo * relu_prime(Zh)

	dWo = Eo * H
	dWh = Eh * X

	Wh -= lr * dWh
	Wo -= lr * dWo


	
	