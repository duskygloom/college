import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.BorderFactory;
import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.ImageIcon;

public class QuadraticEquation 
{
    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            var frame = new Frame("Quadratic Equation");
            frame.setVisible(true);
        });
    }
}

class Frame extends JFrame implements ActionListener
{
    private Component pane;
    private TermField A, B, C;
    private EquationLabel display;
    private Complex[] roots;
    private RootText rootA, rootB;

    public static Color bgcolor = new Color(21, 21, 21);
    public static Color fgcolor = Color.WHITE;
    public static Color container = Color.DARK_GRAY;
    public static Color onContainer = Color.LIGHT_GRAY;

    Frame(String title) {
        super(title);
        setSize(500, 300);
        setLocationRelativeTo(null);
        setIconImage(new ImageIcon("letter-i.png").getImage());
        pane = getContentPane();
        pane.setBackground(bgcolor);
        pane.setForeground(fgcolor);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
        placeComponents();
    }

    private void placeComponents() {
        A = new TermField(this);
        B = new TermField(this);
        C = new TermField(this);
        display = new EquationLabel();
        var equationDisplay = new ThemedPanel();
        equationDisplay.add(display);
        var rootsDisplay = new ThemedPanel();
        rootsDisplay.setLayout(new BoxLayout(rootsDisplay, BoxLayout.PAGE_AXIS));
        roots = Complex.getRoots(A.getNumber(), B.getNumber(), C.getNumber());
        rootA = new RootText(roots[0]);
        rootB = new RootText(roots[1]);
        rootsDisplay.add(Box.createVerticalGlue());
        rootsDisplay.add(rootA);
        rootsDisplay.add(Box.createVerticalStrut(6));
        rootsDisplay.add(rootB);
        rootsDisplay.add(Box.createVerticalGlue());
        var equationPanel = new ThemedPanel();
        equationPanel.setLayout(new GridLayout(2, 3, 6, 6));
        equationPanel.add(A);
        equationPanel.add(B);
        equationPanel.add(C);
        equationPanel.add(new BetterLabel("A"));
        equationPanel.add(new BetterLabel("B"));
        equationPanel.add(new BetterLabel("C"));
        add(equationDisplay, BorderLayout.NORTH);
        add(rootsDisplay, BorderLayout.CENTER);
        add(equationPanel, BorderLayout.SOUTH);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == A || e.getSource() == B || e.getSource() == C) {
            double a = A.getNumber();
            double b = B.getNumber();
            double c = C.getNumber();
            display.refreshText(a, b, c);
            roots = Complex.getRoots(a, b, c);
            rootA.refreshText(roots[0]);
            rootB.refreshText(roots[1]);
			if (Complex.areEqual(rootA.root, rootB.root)) rootB.setVisible(false);
			else rootB.setVisible(true);
        }
    }
}

class ThemedPanel extends JPanel
{
    ThemedPanel() {
        super();
        setBackground(Frame.bgcolor);
        setForeground(Frame.fgcolor);
        setPreferredSize(new Dimension(0, 80));
        setBorder(BorderFactory.createEmptyBorder(6, 6, 6, 6));
    }
}

class BetterLabel extends JLabel
{
    BetterLabel(String text) {
        super(text);
        setHorizontalAlignment(JLabel.CENTER);
        setFont(new Font(Font.MONOSPACED, Font.BOLD, 20));
        setForeground(Frame.onContainer);
    }
}

class EquationLabel extends JLabel
{
    private double a, b, c;

    EquationLabel() {
        super();
        setFont(new Font(Font.MONOSPACED, Font.BOLD, 24));
        setForeground(Frame.onContainer);
        refreshText(0.0, 0.0, 0.0);
    }

    void refreshText(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
        String toDisplay = String.valueOf(a) + "x\u00B2";
        if (b < 0.0) toDisplay += " - " + String.valueOf(-b) + "x";
        else toDisplay += " + " + String.valueOf(b) + "x";
        if (c < 0.0) toDisplay += " - " + String.valueOf(-c);
        else toDisplay += " + " + String.valueOf(c);
        setText(toDisplay);
    }
}

class Complex
{
    public double real, imag;

    Complex(double real, double imag) {
        this.real = real;
        this.imag = imag;
    }

    public static double round(double number) {
        // returns the double rounded upto 4 decimal places
        if (Double.isNaN(number)) return Double.NaN;
        return Math.round(number*10000) / 10000.0;
    }

	public static boolean areEqual(Complex a, Complex b) {
		if (a.real == b.real && a.imag == b.imag) return true;
		return false;
	}

    public static Complex[] getRoots(double a, double b, double c) {
        Complex[] roots = new Complex[2];
        double d = b*b - 4*a*c;
        if (d < 0) {
            roots[0] = new Complex(round(-b/(2*a)), round(Math.sqrt(-d)/(2*a)));
            roots[1] = new Complex(round(-b/(2*a)), round(-Math.sqrt(-d)/(2*a)));
        } else if (d == 0) {
            roots[0] = new Complex(round(-b/(2*a)), 0.0);
            roots[1] = new Complex(round(-b/(2*a)), 0.0);
        } else {
            roots[0] = new Complex(round((-b+Math.sqrt(d))/(2*a)), 0.0);
            roots[1] = new Complex(round((-b-Math.sqrt(d))/(2*a)), 0.0);
        }
        return roots;
    }
}

class RootText extends JLabel
{
    public Complex root;

    RootText(Complex root) {
        super();
        this.root = root;
        setFont(new Font(Font.MONOSPACED, Font.BOLD, 24));
        setForeground(Frame.onContainer);
        setAlignmentX(CENTER_ALIGNMENT);
        setVerticalTextPosition(JLabel.CENTER);
        refreshText(root);
    }

    void refreshText(Complex root) {
        this.root = root;
        if (root.imag == 0.0) setText(String.valueOf(root.real));
        else if (root.imag < 0.0) setText(String.valueOf(root.real) + " - " + String.valueOf(-root.imag) + "i");
        else setText(String.valueOf(root.real) + " + " + String.valueOf(root.imag) + "i");
    }
}

class TermField extends JTextField
{
    private double number;

    TermField(ActionListener listener) {
        super();
        addActionListener(listener);
        setFont(new Font(Font.MONOSPACED, Font.BOLD, 16));
        setBackground(Frame.container);
        setForeground(Frame.onContainer);
        setCaretColor(Frame.onContainer);
        setBorder(BorderFactory.createLineBorder(Frame.onContainer, 3, true));
        setHorizontalAlignment(JTextField.CENTER);
        number = 0.0;
        setText(String.valueOf(number));
    }

    public void refreshText() {
        setText(String.valueOf(number));
    }

    public double getNumber() {
        try {
            number = Double.parseDouble(getText());
        } catch (NumberFormatException e) {}
        return number;
    }
}
