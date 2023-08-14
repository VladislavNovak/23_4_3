## <font color="tomato">Анализ заполненности вагонов в поезде</font>

В поезде всего 10 вагонов. 
В каждом из этих вагонов может находиться до 20 пассажиров — это их оптимальное количество. 
Проанализируйте количество людей в каждом вагоне и сначала сообщите об излишне заполненных вагонах, 
далее о вагонах с пустыми пассажирскими местами. В заключение выведите общее количество пассажиров во всех вагонах.

При старте программы пользователь вводит количество пассажиров в каждом вагоне. 
Замечания о вагонах должны выводиться в стандартную консоль.

При выполнении задания пользоваться нельзя напрямую пользоваться for-циклами, только опосредованно, через макросы.

### <font color="tomato">Советы и рекомендации</font>

С помощью макроса реализуйте модульный способ вызова функции над элементами массива. 
Сами функции реализуйте отдельно, в виде обычных классических функций (не макросов).

Модульный способ вызова функции печати текста через макрос:

```c++
#define CALL(func) { func("Hello, Skillbox!"); }

void print(std::string str) {
   std::cout << str << std::endl;
}

int main() {
   CALL(print);
   return 0;
}
```