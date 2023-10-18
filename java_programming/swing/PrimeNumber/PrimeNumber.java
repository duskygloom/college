import javax.swing.JFrame;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.BoxLayout;
import java.awt.EventQueue;

public class PrimeNumber 
{
    public static void main(String[] args) {
        EventQueue.invokeLater(() -> {
            var frame = new Frame("Is it prime?");
            frame.setVisible(true);
        });
    }
}

class Frame extends JFrame
{
    private int number;

    Frame(String title) {
        number = 0;
        setupUI(title);
        placeWidgets();
    }

    private void setupUI(String title) {
        setTitle(title);
        setSize(300, 100);
        setLocationRelativeTo(null);
        setDefaultCloseOperation(EXIT_ON_CLOSE);
    }

    private void placeWidgets() {
        var numberInput = new JTextField();
        // numberInput.set(new Insets(10, 10, 10, 10));
        numberInput.setText(String.valueOf(number));
        var primeLabel = new JLabel();
        if (isPrime(number)) primeLabel.setText(String.valueOf(number) + " is a prime number.");
        else primeLabel.setText(String.valueOf(number) + " is not a prime number.");
        numberInput.addActionListener((event) -> {
            try {
                number = Integer.parseInt(numberInput.getText());
                if (isPrime(number)) primeLabel.setText(String.valueOf(number) + " is a prime number.");
                else primeLabel.setText(String.valueOf(number) + " is not a prime number.");
            } catch (NumberFormatException e) {}
        });
        var pane = getContentPane();
        pane.setLayout(new BoxLayout(pane, BoxLayout.PAGE_AXIS));
        pane.add(numberInput);
        pane.add(primeLabel);
    }

    private boolean isPrime(int n) {
        for (int i = 2; i < n; ++i)
            if (n % i == 0) return false;
        return true;
    }
}
