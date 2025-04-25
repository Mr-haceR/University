import re

def normalize_brackets(expr):
    return expr.replace('{', '(').replace('}', ')').replace('[', '(').replace(']', ')')

def tokenize(expression):
    token_pattern = r'\d+\.\d+|\d+|[+\-*/()]'
    return re.findall(token_pattern, expression)

precedence = {'+': 1, '-': 1, '*': 2, '/': 2}

def apply_operator(op, a, b):
    a, b = float(a), float(b)
    if op == '+': return a + b
    if op == '-': return a - b
    if op == '*': return a * b
    if op == '/': return a / b

def evaluate_infix(expression):
    print(f"Expression: \"{expression}\"")
    expression = normalize_brackets(expression)
    tokens = tokenize(expression)
    print("\nTokens:")
    for token in tokens:
        print(f"Token: {token}")

    ops = []
    values = []

    def pop_and_eval():
        op = ops.pop()
        right = values.pop()
        left = values.pop()
        result = apply_operator(op, left, right)
        print(f"Applied operator: {op}")
        print(f"Left: {left} Right: {right} Result: {result}")
        values.append(result)

    for token in tokens:
        if re.match(r'\d+(\.\d+)?', token):
            values.append(token)
        elif token in precedence:
            while (ops and ops[-1] in precedence and precedence[ops[-1]] >= precedence[token]):
                pop_and_eval()
            ops.append(token)
        elif token == '(':
            ops.append(token)
        elif token == ')':
            while ops and ops[-1] != '(':
                pop_and_eval()
            ops.pop()  # remove '('

    while ops:
        pop_and_eval()

    result = values[0]
    print(f"Result: {result}")
    return result

def evaluate_postfix(expression):
    print(f"Expression: \"{expression}\"")
    expression = normalize_brackets(expression)
    tokens = expression.split()
    print("\nTokens:")
    stack = []

    for token in tokens:
        print(f"Token: {token}")
        if token in precedence:
            b = stack.pop()
            a = stack.pop()
            result = apply_operator(token, a, b)
            print(f"Applied operator: {token}")
            print(f"Left: {a} Right: {b} Result: {result}")
            stack.append(result)
        elif token in ("()", "[]", "{}"):
            continue
        else:
            stack.append(token)

    result = stack[0]
    print(f"Result: {result}")
    return result

def evaluate_prefix(expression):
    print(f"Expression: \"{expression}\"")
    expression = normalize_brackets(expression)
    tokens = expression.split()[::-1]
    print("\nTokens:")
    stack = []

    for token in tokens:
        print(f"Token: {token}")
        if token in precedence:
            a = stack.pop()
            b = stack.pop()
            result = apply_operator(token, a, b)
            print(f"Applied operator: {token}")
            print(f"Left: {a} Right: {b} Result: {result}")
            stack.append(result)
        elif token in ("()", "[]", "{}"):
            continue
        else:
            stack.append(token)

    result = stack[0]
    print(f"Result: {result}")
    return result

if __name__ == "__main__":
    while True:
        print("*********************************************************************************************\n" \
            "*                                         Evaluator                                         *\n" \
            "*********************************************************************************************\n" \
            "Menu > \n" \
            "-----------------------------------------\n" \
            "1. Infix\n" \
            "2. Prefix\n" \
            "3. Postfix\n" \
            "4. Exit\n")
        choice = int(input("Enter your choice: "))
        if choice == 1:
            expression = input("Enter the exprssion: ")
            evaluate_infix(expression=expression)
        elif choice == 2:
            expression = input("Enter the exprssion: ")
            evaluate_prefix(expression=expression)
        elif choice == 3:
            expression = input("Enter the exprssion: ")
            evaluate_postfix(expression=expression)
        elif choice == 4:
            break
        else: 
            print("Invalid choice!")