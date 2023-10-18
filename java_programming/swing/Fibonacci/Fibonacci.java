import javax.swing.BorderFactory;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;

public class Fibonacci 
{
    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            var frame = new Frame("Fibonacci Series");
            frame.setVisible(true);
        });
    }
}

class Frame extends JFrame implements ActionListener, KeyListener
{
    private Container pane;
    private FibonacciLabel label;
    private ChangeButton buttonPrev, buttonNext;
    private NField field;
    
    Frame(String title) {
        super(title);
        setSize(500, 300);
        setLocationRelativeTo(null);
        setIconImage(new ImageIcon("number-one.png").getImage());
        pane = getContentPane();
        pane.setBackground(new Color(21, 21, 21));
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        placeComponents();
        label.requestFocusInWindow();
    }

    void placeComponents() {
        label = new FibonacciLabel();
        buttonPrev = new ChangeButton("<-");
        buttonPrev.addActionListener(this);
        buttonNext = new ChangeButton("->");
        buttonNext.addActionListener(this);
        field = new NField();
        field.addActionListener(this);
        field.addKeyListener(this);
        var buttonPanel = new JPanel();
        buttonPanel.setBackground(new Color(21, 21, 21));
        buttonPanel.add(buttonPrev);
        buttonPanel.add(field);
        buttonPanel.add(buttonNext);
        add(label, BorderLayout.CENTER);
        add(buttonPanel, BorderLayout.SOUTH);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == buttonPrev) {
            label.showPrev();
            field.decreaseNumber();
        }
        if (e.getSource() == buttonNext) {
            label.showNext();
            field.increaseNumber();
        }
        if (e.getSource() == field) {
            int number = field.getNumber();
            field.setText(String.valueOf(number));
            label.setNth(number);
        }
    }

    @Override
    public void keyPressed(KeyEvent e) {
        if (e.getKeyCode() == KeyEvent.VK_UP) {
            label.showNext();
            field.increaseNumber();
        }
        if (e.getKeyCode() == KeyEvent.VK_DOWN) {
            label.showPrev();
            field.decreaseNumber();
        }
    }

    @Override
    public void keyReleased(KeyEvent e) {}

    @Override
    public void keyTyped(KeyEvent e) {}
}

class FibonacciLabel extends JLabel
{
    private long a, b;

    FibonacciLabel() {
        super();
        a = 0;
        b = 1;
        setFont(new Font(Font.MONOSPACED, Font.BOLD, 36));
        setBackground(new Color(21, 21, 21));
        setForeground(Color.WHITE);
        setHorizontalAlignment(JLabel.CENTER);
        setText(String.valueOf(a));
    }

    void showNext() {
        b += a;
        a = b - a;
        setText(String.valueOf(a));
    }

    void showPrev() {
        if (a != 0) {
            a = b - a;
            b -= a;
            setText(String.valueOf(a));
        }
    }

    long getNthFibonacci(int n) {
        double rootFive = Math.sqrt(5);
        double result = Math.pow((1+rootFive), n) - Math.pow((1-rootFive), n);
        result /= rootFive * Math.pow(2, n);
        return (long)result;
    }

    void setNth(int n) {
        if (n >= 0) {
            a = getNthFibonacci(n);
            b = getNthFibonacci(n+1);
            setText(String.valueOf(a));
        }
    }
}

class NField extends JTextField
{
    private int number;

    NField() {
        super();
        setPreferredSize(new Dimension(200, 40));
        setFont(new Font(Font.MONOSPACED, Font.BOLD, 20));
        setBackground(Color.DARK_GRAY);
        setForeground(Color.LIGHT_GRAY);
        setBorder(BorderFactory.createLineBorder(Color.LIGHT_GRAY, 2));
        setCaretColor(Color.LIGHT_GRAY);
        setHorizontalAlignment(JTextField.CENTER);
        number = 0;
        setText(String.valueOf(number));
    }

    int getNumber() {
        try {
            int maybeNumber = Integer.parseInt(getText());
            if (maybeNumber >= 0) number = maybeNumber;
        } catch (NumberFormatException e) {}
        return number;
    }

    void decreaseNumber() {
        if (number != 0) {
            --number;
            setText(String.valueOf(number));
        }
    }

    void increaseNumber() {
        ++number;
        setText(String.valueOf(number));
    }
}

class ChangeButton extends JButton
{
    ChangeButton(String text) {
        super(text);
        setPreferredSize(new Dimension(60, 40));
        setFont(new Font(Font.MONOSPACED, Font.BOLD, 20));
        setBackground(Color.DARK_GRAY);
        setForeground(Color.LIGHT_GRAY);
        setBorder(BorderFactory.createLineBorder(Color.LIGHT_GRAY, 1, true));
        setFocusPainted(false);
    }
}
