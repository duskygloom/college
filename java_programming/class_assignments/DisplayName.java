import javax.swing.JFrame;
import javax.swing.JLabel;

import java.awt.BorderLayout;
import java.awt.EventQueue;
import java.awt.Font;

public class DisplayName 
{
	public static void main(String args[]) {
		EventQueue.invokeLater(() -> {
			Frame frame = new Frame();
			frame.setVisible(true);
		});
	}
}

class Frame extends JFrame
{
	Frame() {
		setSize(400, 200);
		setTitle("Display name");
		setLocationRelativeTo(null);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		placeComponents();
	}

	private void placeComponents() {
		JLabel label = new JLabel("Your mom");
		label.setHorizontalAlignment(JLabel.CENTER);
		label.setFont(new Font("Consolas", Font.BOLD, 32));
		add(label, BorderLayout.CENTER);
	}
}