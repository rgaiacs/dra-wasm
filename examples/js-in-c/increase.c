#include <emscripten.h>

void increase_number() {
  int n = EM_ASM_INT({
    const number_span = document.getElementById("number");
    const number = Number(number_span.innerText);
    return number;
  });

  n = n + 1;

  EM_ASM({
    const number_span = document.getElementById("number");
    number_span.innerText = $0;
  }, n);
}