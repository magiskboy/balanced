from queue import LifoQueue


terms = [('(', ')'), ('[', ']'), ('{', '}')]


def match(open_term, close_term):
    for term in terms:
        if term[0] == open_term:
            return term[1] == close_term
    return False


def is_open_term(c):
    for open_term, _ in terms:
        if open_term == c:
            return True
    return False


def is_balanced(expression):
    stack = LifoQueue()
    for c in expression:
        if is_open_term(c):
            stack.put(c)
        else:
            if stack.empty() or not match(stack.get(), c):
                return False
    return stack.empty()


if __name__ == '__main__':
    expression = '(()[){([{()}])})'
    print(is_balanced(expression))
