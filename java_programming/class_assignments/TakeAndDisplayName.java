import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class TakeAndDisplayName
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
	private JTextField textbox;

	Frame() {
		setSize(400, 300);
		setTitle("Take and display name");
		setLocationRelativeTo(null);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		placeComponents();
	}

	private void placeComponents() {
		label = new JLabel();
		label.setHorizontalAlignment(JLabel.CENTER);
		label.setFont(new Font(Font.MONOSPACED, Font.BOLD, 32));
		var panel = new JPanel();
		textbox = new JTextField();
		textbox.setHorizontalAlignment(JTextField.CENTER);
		textbox.setPreferredSize(new Dimension(200, 40));
		textbox.setFont(new Font(Font.MONOSPACED, Font.BOLD, 26));
		textbox.addActionListener(this);
		panel.add(textbox);
		add(label, BorderLayout.CENTER);
		add(panel, BorderLayout.SOUTH);
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == textbox) label.setText(textbox.getText());
	}
}