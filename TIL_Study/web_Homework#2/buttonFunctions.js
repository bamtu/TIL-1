var firstNumber = "";
var savePreviousNumber = "";
var saveOperator = "";

var CHANGE_PRINTNUMBERBOARD = 0;
var CHANGE_PRINTPREVIOUSNUMBERBOARD = 1;
var CHANGE_PRINTOPERATORBOARD = 2;

//////////////////////////////////////////////////////////

function clearFirstNumber() {
    firstNumber = "";
}

function clearPreviousNumber() {
    savePreviousNumber = "";
}

function clearOperator() {
    saveOperator = "";
}

function clearAllVariables() {
    clearFirstNumber();
    clearPreviousNumber();
    clearOperator();
    
    printToBoard(CHANGE_PRINTNUMBERBOARD);
    printToBoard(CHANGE_PRINTPREVIOUSNUMBERBOARD);
    printToBoard(CHANGE_PRINTOPERATORBOARD);
}

//////////////////////////////////////////////////////////

function printToBoard(type) {
    var targetBoard = 0;
    
    if (type == CHANGE_PRINTNUMBERBOARD) {
        targetBoard = document.getElementById("printNumberBoard");

        targetBoard.innerHTML = firstNumber;
    }
    
    else if (type == CHANGE_PRINTPREVIOUSNUMBERBOARD) {
        targetBoard = document.getElementById("printPreviousBoard");

        targetBoard.innerHTML = savePreviousNumber;   
    }
    
    else if (type == CHANGE_PRINTOPERATORBOARD) {
        targetBoard = document.getElementById("printOperatorBoard");

        targetBoard.innerHTML = saveOperator;
    }
}

function concateToFirstNumber(number) {
    if (firstNumber == "" && (number == "0" || number == "00")) {
        return;
    }
    
    else if (firstNumber == "" && number == ".") {
        number = "0.";
    }
    
    firstNumber = "" + firstNumber + number;
}

function concateToPreviousNumber(number) {
    savePreviousNumber = "" + savePreviousNumber + number;
}

function isAlreadyPressOperatorButton() {
    if (saveOperator != "") {
        return true;
    }
    
    return false;
}

function throwFirstNumberToPreviousNumber(number) {
    if (savePreviousNumber != "") {
        return;
    }
    
    concateToPreviousNumber(number);
    printToBoard(CHANGE_PRINTPREVIOUSNUMBERBOARD);
    
    clearFirstNumber();
    printToBoard(CHANGE_PRINTNUMBERBOARD);
}

function inputNumber(number) {
    if (!isAlreadyPressOperatorButton()) {
        concateToFirstNumber(number);
        printToBoard(CHANGE_PRINTNUMBERBOARD);
    }
    
    else {
        throwFirstNumberToPreviousNumber(firstNumber);
        
        concateToFirstNumber(number);
        printToBoard(CHANGE_PRINTNUMBERBOARD);
    }
}

function pressButton(button) {
    inputNumber(button);
}

//////////////////////////////////////////////////////////

function concateToSaveOperator(operator) {
    if (firstNumber == "") {
        return;
    }
    
    saveOperator = "" + operator;
}

function inputOperator(operator) {
    concateToSaveOperator(operator);
    printToBoard(CHANGE_PRINTOPERATORBOARD);
}

function pressOperator(operator) {
    inputOperator(operator);
}

//////////////////////////////////////////////////////////

function throwPreviousNumberToFirstNumber(number) {
    concateToFirstNumber(number);
    printToBoard(CHANGE_PRINTNUMBERBOARD);
    
    clearPreviousNumber();
    printToBoard(CHANGE_PRINTPREVIOUSNUMBERBOARD);
}

function cancelLastFirstNumber() {
    firstNumber = firstNumber.slice(0, -1);
}

function cancelOperator() {
    saveOperator = saveOperator.slice(0, -1);
}

function cancelNumber() {
    if (firstNumber != "") {
        cancelLastFirstNumber();
        printToBoard(CHANGE_PRINTNUMBERBOARD);    
    }
    
    else if (saveOperator != "") {
        cancelOperator();
        printToBoard(CHANGE_PRINTOPERATORBOARD);
    }
    
    else if (savePreviousNumber != "") {
        throwPreviousNumberToFirstNumber(savePreviousNumber);
    }
}

function pressCancelButton() {
    cancelNumber();
}

//////////////////////////////////////////////////////////

function plus(firstNumber, previousNumber) {
    return firstNumber + previousNumber;
}

function minus(firstNumber, previousNumber) {
    return firstNumber - previousNumber;
}

function multiple(firstNumber, previousNumber) {
    return firstNumber * previousNumber;
}

function divide(firstNumber, previousNumber) {
    return firstNumber / previousNumber;
}

function isIntOrFloat(number) {
    if(number.charAt(0) == '0') {
        return parseFloat(number);
    }
    
    return parseInt(number);
}

function isAllVariablesAreFull() {
    if (firstNumber == "" || savePreviousNumber == "" || saveOperator == "") {
        return false;
    }
    
    return true;
}

function executeCalculation() {
    var result = 0;
    var frontNumber = 0;
    var backNumber = 0;
    
    if (!isAllVariablesAreFull()) {
        return;
    }
    
    else {
        frontNumber = isIntOrFloat(savePreviousNumber);
        backNumber = isIntOrFloat(firstNumber);
        
        switch(saveOperator) {
            case "+":
                result = plus(frontNumber, backNumber);
                break;
                
            case "-":
                result = minus(frontNumber, backNumber);
                break;
                
            case "*":
                result = multiple(frontNumber, backNumber);
                break;
                
            case "/":
                result = divide(frontNumber, backNumber);
                break;
        }
        
        clearAllVariables();
        concateToFirstNumber(result);
        
        printToBoard(CHANGE_PRINTNUMBERBOARD);
        printToBoard(CHANGE_PRINTOPERATORBOARD);
        printToBoard(CHANGE_PRINTPREVIOUSNUMBERBOARD);
    }
}

function pressResultButton() {
    executeCalculation();
}

//////////////////////////////////////////////////////////

var eventPress1Button = document.getElementById("1Button");
eventPress1Button.addEventListener('click',function() {pressButton(1)});

var eventPress2Button = document.getElementById("2Button");
eventPress2Button.addEventListener('click',function() {pressButton(2)});

var eventPress3Button = document.getElementById("3Button");
eventPress3Button.addEventListener('click',function() {pressButton(3)});

var eventPress4Button = document.getElementById("4Button");
eventPress4Button.addEventListener('click',function() {pressButton(4)});

var eventPress5Button = document.getElementById("5Button");
eventPress5Button.addEventListener('click',function() {pressButton(5)});

var eventPress6Button = document.getElementById("6Button");
eventPress6Button.addEventListener('click',function() {pressButton(6)});

var eventPress7Button = document.getElementById("7Button");
eventPress7Button.addEventListener('click',function() {pressButton(7)});

var eventPress8Button = document.getElementById("8Button");
eventPress8Button.addEventListener('click',function() {pressButton(8)});

var eventPress9Button = document.getElementById("9Button");
eventPress9Button.addEventListener('click',function() {pressButton(9)});

var eventPress0Button = document.getElementById("0Button");
eventPress0Button.addEventListener('click',function() {pressButton(0)});

var eventPress00Button = document.getElementById("doubleZeroButton");
eventPress00Button.addEventListener('click',function() {pressButton("00")});

var eventPressDotButton = document.getElementById("dotButton");
eventPressDotButton.addEventListener("click",function(){pressButton(".")})

//////////////////////////////////////////////////////////

var eventPressPlusButton = document.getElementById("plusButton");
eventPressPlusButton.addEventListener("click",function() {pressOperator("+")});

var eventPressMinusButton = document.getElementById("minusButton");
eventPressMinusButton.addEventListener("click",function() {pressOperator("-")});

var eventPressMultipleButton = document.getElementById("multipleButton");
eventPressMultipleButton.addEventListener("click",function() {pressOperator("*")});

var eventPressDivideButton = document.getElementById("divideButton");
eventPressDivideButton.addEventListener("click",function() {pressOperator("/")});

//////////////////////////////////////////////////////////

var eventPressClearButton = document.getElementById("clearButton");
eventPressClearButton.addEventListener("click",clearAllVariables);

var eventPressCancelButton = document.getElementById("cancelButton");
eventPressCancelButton.addEventListener("click",pressCancelButton);

//////////////////////////////////////////////////////////

var eventPressResultButton = document.getElementById("resultButton");
eventPressResultButton.addEventListener("click",pressResultButton);