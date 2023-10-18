import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.BorderFactory;

import java.awt.Font;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class NonResizableApp
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
	private ResultLabel label;
	private OperandField fieldA, fieldB;
	private OperationButton buttonAdd, buttonSub, buttonMul, buttonDiv;

	Frame() {
		setLocationRelativeTo(null);
		setTitle("Cannot resize this mf!");
		setResizable(false);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		placeComponents();
		pack();
	}

	private void placeComponents() {
		label = new ResultLabel(10, 10, 400, 100);
		fieldA = new OperandField(20, 120, this);
		fieldB = new OperandField(220, 120, this);
		buttonAdd = new OperationButton(20, 210, "+", this);
		buttonSub = new OperationButton(120, 210, "-", this);
		buttonMul = new OperationButton(220, 210, "*", this);
		buttonDiv = new OperationButton(320, 210, "/", this);
		JPanel panel = new JPanel();
		panel.setPreferredSize(new Dimension(420, 280));
		panel.setLayout(null);
		panel.add(label);
		panel.add(fieldA);
		panel.add(fieldB);
		panel.add(buttonAdd);
		panel.add(buttonSub);
		panel.add(buttonMul);
		panel.add(buttonDiv);
		add(panel);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == buttonAdd) label.setResult(fieldA.getOperand() + fieldB.getOperand());
		else if (e.getSource() == buttonSub) label.setResult(fieldA.getOperand() - fieldB.getOperand());
		else if (e.getSource() == buttonMul) label.setResult(fieldA.getOperand() * fieldB.getOperand());
		else if (e.getSource() == buttonDiv) label.setResult(fieldA.getOperand() / fieldB.getOperand());
	}
}

class ResultLabel extends JLabel
{
	private double result;

	ResultLabel(int x, int y, int ax, int ay) {
		setBounds(x, y, ax, ay);
		setBorder(BorderFactory.createLineBorder(Color.BLACK, 2));
		setHorizontalAlignment(CENTER);
		setFont(new Font(Font.MONOSPACED, Font.BOLD, 20));
		setResult(0);
	}

	void setResult(double num) {
		result = num;
		setText("Result: " + result);
	}
}

class OperandField extends JTextField
{
	private double operand;

	OperandField(int x, int y, ActionListener listener) {
		setBounds(x, y, 180, 80);
		setHorizontalAlignment(CENTER);
		addActionListener(listener);
		setBorder(BorderFactory.createLineBorder(Color.BLACK, 1));
		setFont(new Font(Font.MONOSPACED, Font.BOLD, 20));
		operand = 0;
		setText(String.valueOf(operand));
	}

	double getOperand() {
		try {
			operand = Double.parseDouble(getText());
		} catch (NumberFormatException e) {}
		return operand;
	}
}

class OperationButton extends JButton
{
	OperationButton(int x, int y, String operation, ActionListener listener) {
		setBounds(x, y, 80, 60);
		setBorder(BorderFactory.createLineBorder(Color.BLACK, 1));
		setFocusable(false);
		addActionListener(listener);
		setFont(new Font(Font.MONOSPACED, Font.BOLD, 20));
		setText(operation);
	}
}

