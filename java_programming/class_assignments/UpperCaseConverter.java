import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JTextField;

import java.awt.Font;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.BorderLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class UpperCaseConverter
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
	private JTextField field;
	private JButton button;

	Frame() {
		setSize(400, 200);
		setTitle("Convert to upper case");
		setLocationRelativeTo(null);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		placeComponents();
	}

	private void placeComponents() {
		setupLabel();
		setupField();
		setupButton();
		add(field, BorderLayout.NORTH);
		add(label, BorderLayout.CENTER);
		add(button, BorderLayout.SOUTH);
	}

	private void setupLabel() {
		label = new JLabel();
		label.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 28));
		label.setHorizontalAlignment(JLabel.CENTER);
	}

	private void setupField() {
		field = new JTextField();
		field.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 24));
		field.setHorizontalAlignment(JTextField.CENTER);
		field.addActionListener(this);
	}

	private void setupButton() {
		button = new JButton();
		button.setFont(new Font(Font.MONOSPACED, Font.PLAIN, 18));
		button.addActionListener(this);
		button.setText("Capitalize");
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == button || e.getSource() == field) label.setText(field.getText().toUpperCase());
	}
}

