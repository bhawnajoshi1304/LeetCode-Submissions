class ZeroEvenOdd {
    private int n;
    private Semaphore zero, even, odd;

    public ZeroEvenOdd(int n) {
        this.n = n;
        this.zero = new Semaphore(1);
        this.even = new Semaphore(0);
        this.odd = new Semaphore(0);
    }

    // printNumber.accept(x) outputs "x", where x is an integer.
    public void zero(IntConsumer printNumber) throws InterruptedException {
        boolean isOdd = true;
        for (int i = 1; i <= n; i += 1) {
            zero.acquire();
            printNumber.accept(0);
            if (isOdd) {
                odd.release();
            }else{
                even.release();
            }
            isOdd=!isOdd;
        }
    }

    public void even(IntConsumer printNumber) throws InterruptedException {
        for (int i = 2; i <= n; i += 2) {
            even.acquire();
            printNumber.accept(i);
            zero.release();
        }
    }

    public void odd(IntConsumer printNumber) throws InterruptedException {
        for (int i = 1; i <= n; i += 2) {
            odd.acquire();
            printNumber.accept(i);
            zero.release();
        }
    }
}