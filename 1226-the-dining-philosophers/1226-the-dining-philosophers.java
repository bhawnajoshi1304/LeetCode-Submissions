class DiningPhilosophers {
    private Semaphore p;
    private Semaphore[] f;

    public DiningPhilosophers() {
        this.p = new Semaphore(4);
        this.f = new Semaphore[5];
        for (int i = 0; i < 5; i++)
            this.f[i] = new Semaphore(1);
    }

    // call the run() method of any runnable to execute its code
    public void wantsToEat(int philosopher,
            Runnable pickLeftFork,
            Runnable pickRightFork,
            Runnable eat,
            Runnable putLeftFork,
            Runnable putRightFork) throws InterruptedException {
        p.acquire();
        int left = philosopher % 5;
        int right = (philosopher + 4) % 5;
        f[left].acquire();
        f[right].acquire();
        pickLeftFork.run();
        pickRightFork.run();
        eat.run();
        putLeftFork.run();
        f[left].release();
        putRightFork.run();
        f[right].release();
        p.release();
    }
}