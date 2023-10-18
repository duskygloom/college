public class ComparingThreadPriorities 
{
    public static void main(String[] args) {
        var minThread = new ClickerRunnable("minimum", Thread.MIN_PRIORITY);
        var normThread = new ClickerRunnable("normal", Thread.NORM_PRIORITY);
        var maxThread = new ClickerRunnable("maximum", Thread.MAX_PRIORITY);
        minThread.start();
        normThread.start();
        maxThread.start();
        try {
            Thread.sleep(10);
        } catch (InterruptedException e) {
            System.out.println("Thread interrupted.");
        }
        // minThread.count = normThread.count = maxThread.count = false;
        minThread.stop();
        normThread.stop();
        maxThread.stop();
        System.out.println(minThread.counter + " " + normThread.counter + " " + maxThread.counter);
    }
}

class Clicker extends Thread 
{
    volatile long counter = 0;
    volatile boolean count = true;

    Clicker(String name, int priority) {
        setName(name);
        setPriority(priority);
    }

    @Override
    public void run() {
        while (count) ++counter;
    }

    public long getCounter() {
        count = false;
        return counter;
    }
}

class ClickerRunnable implements Runnable
{
    volatile long counter;
    private volatile boolean count;
    private Thread thread;

    ClickerRunnable(String name, int priority) {
        thread = new Thread(this, name);
        thread.setPriority(priority);
        counter = 0;
        count = true;
    }

    @Override
    public void run() {
        while (count) ++counter;
    }

    public void start() {
        thread.start();
    }

    public void stop() {
        count = false;
        try {
            thread.join();
        } catch (InterruptedException e) {
            System.out.println("Thread interrupted.");
        }
    }
}
