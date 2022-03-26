# Седмица 1 - Enum, структури. Разположение в паметта. Битови полета

# Задача 1:
Да се напише програма, която има структура Person със следните полета: име, години, 
пол(представен чрез изброим тип). Създайте масив от структурата и отпечатайте на екрана хората от конкретен пол, който потребителя ще трябва да въведе.

# Задача 2:
Напишете програма, която въвежда списък от студенти (всеки студент притежава: име , фн и дата на раждане). 
Изведете данните за всички студенти сортирани по факултетен номер. hint(датата на раждане има ден , месец , година)

# Задача 3:
Да се дефинира структура Planet, определяща планета по име (символен низ), разстояние от слънцето, диаметър и маса (реални числа). 
Да се дефинират функции, изпълняващи следните действия:

- въвежда данни за планета от клавиатурата;
- извежда данните за планета;
- връща като резултат броя секунди, които са необходими на светлината да достигне от слънцето до планетата 
(да се приеме, че светлината има скорост 299792 km/s и че разстоянието на планетата до слънцето е зададено в километри).
- създава едномерен масив от планети с фиксиран размер и въвежда данните за тях от стандартния вход;
- извежда данните за планетите от масив, подаден на функцията като параметър;

# Задача 4:
Напишете програма, която има като изброим тип трите основни цвята според цветовия модел RGB. Направете структура, която има поле масив от три стойности представени от изброимия тип и поле за име на новосъздадения цвят. Напишете функция, която по подаден обект от структурата, от масива с цветове връща цвета спрямо трите стойности и слага това име на полето с име в структурата

Пример:
масив от три стойности: [None, None, Blue] -> Blue
[Red, Green, Blue] -> White
[Red, Green, None] -> Yellow


# Задача 5:
Напишете програма, която има структура, която пази информация за характеристики на кола:

- цена
- цвят
- марка
- модел (може да добавите и още характеристики)
Използвайте структурата от първа задача като дабивето в нея поле за заплата на човек. 
Създайте масив от хора и масив от коли с техните характеристики. Напишете функция, която по подадени двата масива принтират за всеки човек какъв набор от коли може да закупи:

- човек може да закупи кола ако цената на колата е по-малка от 30% от заплатата му.