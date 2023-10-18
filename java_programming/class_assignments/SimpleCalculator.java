import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JButton;
import javax.swing.JTextField;

import java.awt.Font;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SimpleCalculator
{
	public static void main(String args[]) {
		EventQueue.invokeLater(() -> {
			Frame frame = new Frame();
			frame.setVisible(true);
		});
	}
}

class Frame extends JFrame implements ActionListener
{
	private JLabel label;
	private Button addButton;
	private Button subButton;
	private Button proButton;
	private Button divButton;
	private TextField operandA;
	private TextField operandB;

	Frame() {
		setSize(600, 400);
		setTitle("Simple Calculator");
		setLocationRelativeTo(null);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		placeComponents();
	}

	private void placeComponents() {
		label = new JLabel("Result: ");
		label.setFont(new Font(Font.MONOSPACED, Font.BOLD, 36));
		label.setHorizontalAlignment(JLabel.CENTER);
		var operandPanel = new JPanel();
		operandA = new TextField();
		operandB = new TextField();
		operandPanel.add(operandA);
		operandPanel.add(operandB);
		var operationPanel = new JPanel();
		addButton = new Button("+", this);
		subButton = new Button("-", this);
		proButton = new Button("*", this);
		divButton = new Button("/", this);
		operationPanel.add(addButton);
		operationPanel.add(subButton);
		operationPanel.add(proButton);
		operationPanel.add(divButton);
		add(operandPanel, BorderLayout.NORTH);
		add(label, BorderLayout.CENTER);
		add(operationPanel, BorderLayout.SOUTH);
	}

	private double getNumber(String s) {
		try {
			return Double.parseDouble(s);
		} catch (NumberFormatException e) {
			return 0.0;
		}
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == addButton)
			label.setText(String.valueOf(getNumber(operandA.getText()) + getNumber(operandB.getText())));
		if (e.getSource() == subButton)
			label.setText(String.valueOf(getNumber(operandA.getText()) - getNumber(operandB.getText())));
		if (e.getSource() == proButton)
			label.setText(String.valueOf(getNumber(operandA.getText()) * getNumber(operandB.getText())));
		if (e.getSource() == divButton)
			label.setText(String.valueOf(getNumber(operandA.getText()) / getNumber(operandB.getText())));
	}
}

class TextField extends JTextField
{
	TextField() {
		setPreferredSize(new Dimension(200, 40));
		setFont(new Font(Font.MONOSPACED, Font.BOLD, 24));
		setHorizontalAlignment(JTextField.CENTER);
	}
}

class Button extends JButton
{
	Button(String text, ActionListener e) {
		setPreferredSize(new Dimension(80, 40));
		setFont(new Font(Font.MONOSPACED, Font.BOLD, 24));
		setText(text);
		addActionListener(e);
	}
}