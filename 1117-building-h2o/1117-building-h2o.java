class H2O {
    private Semaphore h,o,h2o;
    public H2O() {
        this.h = new Semaphore(2);
        this.o = new Semaphore(1);
        this.h2o = new Semaphore(0);
    }

    public void hydrogen(Runnable releaseHydrogen) throws InterruptedException {
		h.acquire();
        h2o.release();
        // releaseHydrogen.run() outputs "H". Do not change or remove this line.
        releaseHydrogen.run();
    }

    public void oxygen(Runnable releaseOxygen) throws InterruptedException {
        o.acquire();
        h2o.acquire(2);
        // releaseOxygen.run() outputs "O". Do not change or remove this line.
		releaseOxygen.run();
        o.release();
        h.release(2);
    }
}