import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.GridLayout;

public class Calculator 
{
    public static void main(String[] args) {
        Frame frame = new Frame("Super Basic Calculator");
        frame.setVisible(true);
    }
}

class ColorScheme 
{
    static Color background = new Color(32, 32, 32);
    static Color foreground = new Color(255, 255, 255);
    static Color accent = new Color(94, 205, 255);
}

class Frame extends JFrame
{
    Frame(String title) {
        super();
        setupUI(title);
        createWidgets();
    }

    void setupUI(String title) {
        setTitle(title);
        setSize(600, 400);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setLayout(new BoxLayout(getContentPane(), BoxLayout.Y_AXIS));
        getContentPane().setBackground(ColorScheme.background);
        getContentPane().setForeground(ColorScheme.foreground);
    }

    void createWidgets() {
        var operandA = new OperandField();
        var operandB = new OperandField();
        var operandPanel = new Panel();
        operandPanel.setLayout(new BoxLayout(operandPanel, BoxLayout.X_AXIS));
        operandPanel.add(Box.createHorizontalStrut(6));
        operandPanel.add(operandA);
        operandPanel.add(Box.createHorizontalStrut(6));
        operandPanel.add(operandB);
        operandPanel.add(Box.createHorizontalStrut(6));
        var result = new ResultArea();
        var resultPanel = new Panel();
        resultPanel.setLayout(new BoxLayout(resultPanel, BoxLayout.X_AXIS));
        resultPanel.add(result);
        var buttonAdd = new OperationButton("+");
        buttonAdd.addActionListener((event) -> {
            result.setResult(operandA.getNumber() + operandB.getNumber());
        });
        var buttonSub = new OperationButton("-");
        buttonSub.addActionListener((event) -> {
            result.setResult(operandA.getNumber() - operandB.getNumber());
        });
        var buttonPro = new OperationButton("*");
        buttonPro.addActionListener((event) -> {
            result.setResult(operandA.getNumber() * operandB.getNumber());
        });
        var buttonDiv = new OperationButton("/");
        buttonDiv.addActionListener((event) -> {
            result.setResult(operandA.getNumber() / operandB.getNumber());
        });
        var buttonRem = new OperationButton("%");
        buttonRem.addActionListener((event) -> {
            result.setResult(operandA.getNumber() % operandB.getNumber());
        });
        var buttonPow = new OperationButton("^");
        buttonPow.addActionListener((event) -> {
            result.setResult(Math.pow(operandA.getNumber(), operandB.getNumber()));
        });
        var operationPanel = new Panel();
        var operationGrid = new Grid(2, 4);
        operationPanel.setLayout(operationGrid);
        operationPanel.add(buttonAdd);
        operationPanel.add(buttonSub);
        operationPanel.add(buttonPro);
        operationPanel.add(buttonDiv);
        operationPanel.add(buttonRem);
        operationPanel.add(buttonPow);
        getContentPane().add(operandPanel);
        getContentPane().add(resultPanel);
        getContentPane().add(operationPanel);
    }
}

class OperandField extends JTextField
{
    private double number;

    OperandField() {
        super();
        number = 0.0;
        setFont(new Font("Consolas", Font.PLAIN, 28));
        setHorizontalAlignment(JTextField.CENTER);
        setBackground(ColorScheme.background);
        setForeground(ColorScheme.foreground);
        setCaretColor(ColorScheme.accent);
        setMaximumSize(new Dimension(Integer.MAX_VALUE, 60));
    }

    double getNumber() {
        try {
            number = Double.parseDouble(getText());
        } catch (NumberFormatException e) {}
        return number;
    }
}

class OperationButton extends JButton
{
    OperationButton(String text) {
        super(text);
        setBackground(ColorScheme.accent);
        setFont(new Font("Consolas", Font.BOLD, 20));
        setMaximumSize(new Dimension(Integer.MAX_VALUE, 32));
    }
}

class ResultArea extends JLabel
{
    ResultArea() {
        super();
        setBackground(ColorScheme.background);
        setForeground(ColorScheme.foreground);
        setMaximumSize(new Dimension(Integer.MAX_VALUE, 40));
        setFont(new Font("Consolas", Font.BOLD, 28));
        setHorizontalAlignment(JLabel.CENTER);
        setResult(0.0);
    }

    void setResult(double result) {
        setText("Result: " + result);
    }
}

class Panel extends JPanel
{
    Panel() {
        super();
        setBackground(ColorScheme.background);
        setForeground(ColorScheme.foreground);
    }
}

class Grid extends GridLayout
{
    Grid(int rows, int cols) {
        super(rows, cols, 6, 6);
    }
}
