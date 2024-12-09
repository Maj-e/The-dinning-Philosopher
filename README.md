# Dining Philosophers

The **Dining Philosophers** project is a classic synchronization problem designed to demonstrate the complexities of concurrency in operating systems and how to resolve potential deadlocks, starvation, and race conditions. This project challenges you to implement a solution for a group of philosophers who alternate between thinking and eating, with shared forks as the resource.

---

## Introduction

In the Dining Philosophers problem, a group of philosophers sits around a circular table. Each philosopher alternates between two states: **thinking** and **eating**. To eat, a philosopher requires two forks (one from their left and one from their right). Philosophers cannot pick up both forks simultaneously. The problem revolves around designing a synchronization mechanism that prevents **deadlocks** and ensures that all philosophers eventually get a chance to eat.

---

## Problem Description

1. There are `n` philosophers and `n` forks.
2. Philosophers are numbered from `0` to `n-1`.
3. A philosopher can:
   - **Think**: Spend time in a thinking state.
   - **Eat**: Acquire both the left and right forks to eat.
   - **Wait**: Stay idle if one or both forks are unavailable.
4. The program must avoid:
   - **Deadlock**: A state where no philosopher can make progress.
   - **Starvation**: A philosopher never gets to eat.

---

## Key Objectives

- Implement a multithreaded solution to simulate the philosophers.
- Ensure synchronization using mutexes or semaphores.
- Avoid deadlocks and starvation.
- Maintain clear logging to track philosopher states.

---

## Usage

### 1. Clone the Repository
```bash
git clone https://github.com/your-repo-name/dining-philosophers.git
cd dining-philosophers
