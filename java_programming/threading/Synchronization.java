public class Synchronization 
{
    public static void main(String[] args) {
        var a = new Message("Rahul", "HOOOOOOO");
        var b = new Message("Bijon", "Olla hu obkar");
        var c = new Message("Niloy", "Have something hot.");
        var readerA = new MessageReader("fromRahul", a);
        var readerB = new MessageReader("fromBijon", b);
        var readerC = new MessageReader("fromNiloy", c);
        readerA.stop();
        readerB.stop();
        readerC.stop();
    }
}


class Message
{
    String sender;
    String body;

    Message(String sender, String body) {
        this.sender = sender;
        this.body = body;
    }

    synchronized static void readMessage(Message message) {
        try {
            Thread.sleep(100);
            System.out.print("[" + message.sender + "] ");
            Thread.sleep(1000);
            System.out.println(message.body);
        } catch (InterruptedException e)  {
            System.out.println("Thread interrupted while reading Message "
                + message.hashCode() + ".");
        }
    }
}


class MessageReader implements Runnable
{
    private Thread thread;
    private Message message;

    MessageReader(String name, Message messageObj) {
        thread = new Thread(this, name);
        message = messageObj;
        thread.start();
    }

    @Override
    public void run() {
        Message.readMessage(message);
    }

    public void stop() {
        try {
            thread.join();
        } catch (InterruptedException e) {
            System.out.println("Thread interrupted in the stop function of MessageReader " 
                + this.hashCode() + ".");
        }
    }
}
