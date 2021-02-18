package com.leetcode.reversePolandCalculator;

import java.util.*;

public class ReversePolandCalculator {
    public static void main(String[] args) {

        ReversePolandCalculator reversePolandCalculator = new ReversePolandCalculator();

        String quit = "q";
        System.out.println("'q' for quit, expression for continue: ");
        Scanner scanner = new Scanner(System.in);
        String next = scanner.nextLine();
        while (!quit.equals(next)) {
            System.out.println(reversePolandCalculator.reversePolandCalculate(next));
            next = scanner.nextLine();
        }
    }

    private final char CLEAR_STACK_TO_RIGHT_BRACKET = ')';
    private final char CLEAR_STACK_TO_LEFT_BRACKET = '(';

    /**
     * Central idea of implementation :
     *      all operation are for the character stack
     *      push stack  : empty stack
     *                    the first element that pops up takes precedence over the data stack
     *      clear stack : the first element that pops up has the same priority as '+' or '-'
     *                    clear stack until the first element that pops up equal '('
     *                    then push the element
     *                    the first element that pops up has the same priority as ')'
     *                    clear stack until the first element that pops up equal '('
     *                    then pop stack
     *
     * @param expression
     * @return
     */
    public Double reversePolandCalculate(String expression) {
        List<Object> expressionList = this.getExpressionList(expression);
        HashMap<Character, Integer> toInteger = new HashMap<>(5);
        toInteger.put('+', 1);
        toInteger.put('-', 1);
        toInteger.put('*', 2);
        toInteger.put('/', 2);
        toInteger.put('(', 3);
        toInteger.put(')', 3);

        Stack<Double> doubleStack = new Stack<>();
        Stack<Character> characterStack = new Stack<>();

        while (!expressionList.isEmpty()) {
            Object remove = expressionList.remove(0);
            if (remove instanceof Double) {
                doubleStack.push((Double) remove);
            } else {
                Character tempRemove = (Character) remove;
                if (tempRemove != CLEAR_STACK_TO_RIGHT_BRACKET) {
                    if (!characterStack.isEmpty() && toInteger.get(tempRemove) == 1) {
                        this.clearStackTo(doubleStack, characterStack, tempRemove);
                    }
                    characterStack.push(tempRemove);
                } else {
                    this.clearStackTo(doubleStack, characterStack, tempRemove);
                }
            }
        }

        char clearStackToEnd = '\0';
        this.clearStackTo(doubleStack, characterStack, clearStackToEnd);

        return doubleStack.pop();
    }

    private void clearStackTo(Stack<Double> doubleStack, Stack<Character> characterStack, char flag) {
        while ( !characterStack.isEmpty() && characterStack.peek() != CLEAR_STACK_TO_LEFT_BRACKET) {
            doubleStack.push(this.calculate(doubleStack.pop(), doubleStack.pop(), characterStack.pop()));
        }
        if (flag == CLEAR_STACK_TO_RIGHT_BRACKET) {
            characterStack.pop();
        }
    }

    private Double calculate(Double right, Double left, Character operate) {
        switch (operate) {
            case '+':
                return left + right;
            case '-':
                return left - right;
            case '*':
                return left * right;
            case '/':
                return left / right;
            default:
                System.out.println("invalid operate!!!");
                return null;
        }
    }

    private List<Object> getExpressionList(String expression) {
        LinkedList<Object> objects = new LinkedList<>();

        expression = expression.trim();
        Iterator<String> numbers =
                Arrays.stream(expression.split("[\\+\\*-/\\(\\)]")).filter(w->w.length()!=0).iterator();
        for (char n : expression.replaceAll("[0-9]+", "n").toCharArray()) {
            if (n == 'n') {
                objects.add(Double.valueOf(numbers.next()));
            } else {
                objects.add(n);
            }
        }

        return objects;
    }
}
