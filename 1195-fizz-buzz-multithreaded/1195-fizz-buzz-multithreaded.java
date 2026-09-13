class FizzBuzz {
    private int n;
    private Semaphore f, b, fb, num;

    public FizzBuzz(int n) {
        this.n = n;
        this.num = new Semaphore(1);
        this.f = new Semaphore(0);
        this.b = new Semaphore(0);
        this.fb = new Semaphore(0);
    }

    // printFizz.run() outputs "fizz".
    public void fizz(Runnable printFizz) throws InterruptedException {
        for (int i = 3; i <= n; i += 3) {
            if (i % 5 != 0) {
                f.acquire();
                printFizz.run();
                num.release();
            }
        }
    }

    // printBuzz.run() outputs "buzz".
    public void buzz(Runnable printBuzz) throws InterruptedException {
        for (int i = 5; i <= n; i += 5) {
            if (i % 3 != 0) {
                b.acquire();
                printBuzz.run();
                num.release();
            }
        }
    }

    // printFizzBuzz.run() outputs "fizzbuzz".
    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        for (int i = 15; i <= n; i += 15) {
            fb.acquire();
            printFizzBuzz.run();
            num.release();
        }
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void number(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i += 1) {
            num.acquire();
            if (i % 3 == 0 && i % 5 == 0) {
                fb.release();
            } else if (i % 3 == 0)
                f.release();
            else if (i % 5 == 0)
                b.release();
            else {
                printNumber.accept(i);
                num.release();
            }
        }
    }
}