console.log('Start');

function asyncOperation() {
  return new Promise((resolve) => {
    setTimeout(() => {
      console.log('Asynchronous operation complete');
      resolve();
    }, 2000); // Simulate a long-running task
  });
}

asyncOperation().then(() => {
  console.log('After async operation');
});

console.log('End');
