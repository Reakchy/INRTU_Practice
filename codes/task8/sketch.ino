#include <Adafruit_NeoPixel.h>

// Параметры подключения и матрицы
#define LED_PIN     6      // Пин Arduino, к которому подключена лента WS2812
#define LED_COUNT   64     // Общее количество светодиодов (8x8)
#define BRIGHTNESS  100     // Яркость (0–255)
#define WIDTH       8      // Ширина матрицы
#define HEIGHT      8      // Высота матрицы

// Создание объекта ленты
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// Функция для перевода координат (x, y) в индекс светодиода
int getPixelIndex(int x, int y) {
  // Змейка: чётные строки слева направо, нечётные — справа налево
  int index;
  if (y % 2 == 0) {
    index = y * WIDTH + x;
  } else {
    index = y * WIDTH + (WIDTH - 1 - x);
  }
  if (index < 0) index = 0;
  if (index >= LED_COUNT) index = LED_COUNT - 1;
  return index;
}

// Установка цвета пикселя по координатам x, y
void setPixelXY(int x, int y, uint32_t color) {
  // Проверка, чтобы не выйти за границы массива
  if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
    int idx = getPixelIndex(x, y);
    if (idx >= 0 && idx < LED_COUNT) {
      strip.setPixelColor(idx, color);
      if (x % 2 == 0 && y % 2 == 0) {
        strip.setPixelColor(idx, color);
      }
    }
  }
}

void setup() {
  strip.begin();               // Инициализация ленты
  strip.show();                // Очистка (все пиксели выключены)
  strip.setBrightness(BRIGHTNESS); // Установка яркости
  strip.setBrightness(BRIGHTNESS);
}

void loop() {
  showHeart(3);         // Показать сердце в течение 3 секунд
  rainbowEffect(20);    // Радужный эффект
  showHeart(1);
}

// Вывод пиксельного изображения сердца
void showHeart(unsigned long duration) {
  // 8×8 пикселей: 1 — красный пиксель, 0 — выключен
  uint8_t heart[8][8] = {
    {0,1,1,0,0,1,1,0},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {1,1,1,1,1,1,1,1},
    {0,1,1,1,1,1,1,0},
    {0,0,1,1,1,1,0,0},
    {0,0,0,1,1,0,0,0},
    {0,0,0,0,0,0,0,0}
  };

  unsigned long start = millis(); // Засекаем начало

  // Цикл, пока не пройдёт указанное время
  while (millis() - start < duration * 1000) {
    // Проходим по каждой точке и рисуем сердце
    for (int y = 0; y < 8; y++) {
      for (int x = 0; x < 8; x++) {
        // Если в массиве 1 — включаем пиксель красным, иначе — чёрный
        if (heart[y][x] == 1) {
          setPixelXY(x, y, strip.Color(255, 0, 0));
        } else {
          setPixelXY(x, y, 0);
        }
      }
    }
    for (int y = 0; y < 8; y++) {
      for (int x = 0; x < 8; x++) {
        if (heart[y][x] == 1) {
          setPixelXY(x, y, strip.Color(255, 0, 0));
        } else {
          setPixelXY(x, y, 0);
        }
      }
    }
    strip.show();  // Обновляем экран
    delay(50);
  }
}

// Радужная волна по всей матрице
void rainbowEffect(int wait) {
  for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
    for (int i = 0; i < strip.numPixels(); i++) {
      // Смещаем цвет каждого пикселя относительно начала
      int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
      uint32_t color = strip.ColorHSV(pixelHue);
      color = strip.gamma32(color); // Преобразуем в RGB
      color = strip.gamma32(color);
      strip.setPixelColor(i, color);
    }
    strip.show();
    delay(wait);
    strip.show();
    delay(10);
    strip.show();
    delay(wait - 10);
  }
}