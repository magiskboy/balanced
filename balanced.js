TERMS = ["()", "[]", "{}"];

function Stack() {
  this.data = new Array();
}

Stack.prototype.push = function (item) {
  this.data.unshift(item);
}

Stack.prototype.pop = function() {
  return this.data.shift();
}

Stack.prototype.isEmpty = function() {
  return this.data.length === 0;
}


function Balanced() {
}

Balanced.prototype.match = function(openTerm, closeTerm) {
  for (i = 0; i < 3; ++i) {
    if (TERMS[i][0] === openTerm) {
      return TERMS[i][1] === closeTerm;
    }
  }
  return false;
}

Balanced.prototype.isOpenTerm = function(openTerm) {
  for (i = 0; i < 3; ++i) {
    if (TERMS[i][0] === openTerm) {
      return true;
    }
  }
  return false;
}

Balanced.prototype.isBalanced = function(expression) {
  let stack = new Stack();
  for (i = 0; i < expression.length; ++i) {
    let c = expression[i];
    if (this.isOpenTerm(c)) {
      stack.push(c);
    }
    else {
      if (stack.isEmpty() || !this.match(stack.pop(), c)) {
        return false;
      }
    }
  }
  return stack.isEmpty();
}

test = new Balanced();
console.log(test.isBalanced('[]'));
