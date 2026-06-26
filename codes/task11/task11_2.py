import cv2
import numpy as np

# 1. Загружаем картинку
image = cv2.imread(r"C:\Users\Lev\INRTU_Practice\codes\task11\test_3.jpg")

# 2. Размываем и переводим в HSV
blurred = cv2.GaussianBlur(image, (11, 11), 0)
hsv = cv2.cvtColor(blurred, cv2.COLOR_BGR2HSV)

# 3. Объединяем маски зеленого и желтого цветов
green_mask = cv2.inRange(hsv, np.array((36, 25, 25)), np.array((70, 255, 255)))
yellow_mask = cv2.inRange(hsv, np.array((20, 100, 100)), np.array((36, 255, 255)))
full_mask = cv2.bitwise_or(green_mask, yellow_mask)

# 4. Ищем только внешние контуры
contours, _ = cv2.findContours(full_mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)

# 5. Если объект найден
if len(contours) > 0:
    # Находим самый большой контур
    largest_contour = max(contours, key=cv2.contourArea)
    
    # Считаем центр по габаритам
    x, y, w, h = cv2.boundingRect(largest_contour)
    center_x = int(x + w / 2)
    center_y = int(y + h / 2)
    
    # ИЗМЕНЕНИЕ: Рисуем контур по точной форме объекта
    # Параметры: (картинка, [список_контуров], индекс(-1 значит всё), цвет BGR(красный), толщина)
    cv2.drawContours(image, [largest_contour], -1, (0, 0, 255), 4)
    
    # Рисуем точку центра
    cv2.circle(image, (center_x, center_y), 7, (0, 0, 255), -1)

# 6. Показываем результат
cv2.imshow("Result Exact Shape", image)
cv2.waitKey(0)
cv2.destroyAllWindows()
