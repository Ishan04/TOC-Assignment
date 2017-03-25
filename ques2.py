import re

t = []
postfixNotation = []
oprtr = -10
oprnd = -20
leftbracket = -30
rightbraket = -40
null = -50
				 
def typeof(x):
	if x is '(':
		return leftbracket
	elif x is ')':
		return rightbracket
	elif x is '+' or s is '*' or s is '|':
		return oprtr
	elif x is ' ':
		return null    
	else :
		return oprnd
 
def orderOfExpression(x):
	if x is '(':
		return 0
	elif x is '+' or '|':
		return 1
	elif x is '*':
		return 2
	else:
		return 99

infixNotation = input("Enter infix : ")
for i in infixNotation :
	type = typeof(i)
	if type is leftbracket :
		t.append(i)
	elif type is rightbracket :
		next = t.pop()
		while next is not '(':
			postfixNotation.append(next)
			next = t.pop()
	elif type is oprnd:
		postfixNotation.append(i)
	elif type is oprtr:
		p = orderOfExpression(i)
		while len(t) is not 0 and p <= orderOfExpression(t[-1]) :
			postfixNotation.append(t.pop())
		t.append(i)
	elif type is null:
		continue
				 
while len(t) > 0 :
	postfixNotation.append(t.pop())
	 
print("Postfix Notation: ",''.join(postfixNotation))
