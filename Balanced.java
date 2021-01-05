import java.util.*;


public class Balanced {
    static char[][] TERMS = {{'(', ')'}, {'[', ']'}, {'{', '}'}};

    static boolean match(char openTerm, char closeTerm) {
        for (char[] c : TERMS) {
            if (c[0] == openTerm) {
                return c[1] == closeTerm;
            }
        }
        return false;
    }

    static boolean isOpenTerm(char openTerm) {
        for (char[] c : TERMS) {
            if (c[0] == openTerm) {
                return true;
            }
        }
        return false;
    }

    static boolean isBalanced(String expression) {
        Stack<Character> stack = new Stack<Character>();
        for (char c : expression.toCharArray()) {
            if (isOpenTerm(c)) {
                stack.push(c);
            }
            else {
                if (stack.isEmpty() || !match(stack.pop(), c)) {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }

    static public void main(String[] args) {
        if (args.length < 1) {
            System.err.println("Please pass string to application");
            return;
        }
        if (isBalanced(args[0])) {
            System.out.println("Balanced");
        }
        else {
            System.out.println("Not balanced");
        }
    }
}
