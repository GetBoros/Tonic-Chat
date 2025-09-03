#pragma once

#include <iostream>
#include <stdexcept> // для @throw

/**
 * @file DoxygenCheatSheet.cpp
 * @author Ваше Имя
 * @version 1.0
 * @date 2025-09-03
 * @brief Этот файл является шпаргалкой по основным тегам Doxygen.
 */

 /**
  * @struct UserData
  * @brief Простая структура для хранения данных пользователя.
  * @details Используется как параметр в демонстрационной функции.
  */
struct UserData {
   int userId;       ///< @brief Уникальный идентификатор пользователя. (Комментарий после члена)
   const char* name; ///< @brief Имя пользователя в кодировке UTF-8.
};


//------------------------------------------------------------------------------------//
//                                ОСНОВНАЯ ШПАРГАЛКА                                  //
//------------------------------------------------------------------------------------//

/**
 * @brief Краткое, однострочное описание функции. (Это заголовок)
 *
 * @details
 * Это более подробное, многострочное описание. Здесь можно объяснить логику работы,
 * алгоритмы, особенности и ограничения. Эта функция демонстрирует использование
 * различных тегов Doxygen для документирования кода.
 *
 * @note
 * Обратите внимание, что эта функция может быть ресурсоемкой при
 * значении `forceProcessing = true`.
 *
 * @warning
 * Не передавайте в `outputBuffer` неинициализированный указатель, это приведет к
 * неопределенному поведению!
 *
 * @deprecated
 * Эта функция устарела с версии 2.0. Пожалуйста, используйте новую функцию
 * `processUserDataNew()` вместо этой.
 *
 * @param[in]  user Указатель на входные данные пользователя. Не должен быть nullptr.
 * @param[out] outputBuffer Буфер для записи результата. Должен быть достаточно большим.
 * @param[in]  bufferSize Размер `outputBuffer` в байтах.
 * @param[in]  forceProcessing Флаг, который принудительно запускает сложную обработку.
 *
 * @return Возвращает код состояния операции.
 * @retval 0  Операция прошла успешно.
 * @retval -1 Произошла ошибка (например, неверные входные данные).
 * @retval -2 Размер выходного буфера недостаточен.
 *
 * @throw std::runtime_error Может выбросить исключение, если произошла
 *        критическая системная ошибка, которую нельзя обработать.
 *
 * @see UserData, anotherRelatedFunction()
 *
 * @sa Это синоним для @see (see also - смотри также).
 *
 * Пример использования:
 * @code
 *   UserData user = { 123, "Alice" };
 *   char buffer[256];
 *   int status = processUserData(&user, buffer, sizeof(buffer), false);
 *   if (status == 0) {
 *       printf("Result: %s\n", buffer);
 *   }
 * @endcode
 *
 * @todo Нужно добавить логирование ошибок в файл.
 * @bug При именах длиннее 128 символов происходит переполнение.
 */
int processUserData(const UserData* user, char* outputBuffer, int bufferSize, bool forceProcessing)
{
   // ... здесь могла бы быть реализация функции ...
   if (!user || !outputBuffer) {
      return -1; // Ошибка: неверные входные данные
   }

   const char* message = "Processed successfully";
   if (bufferSize < strlen(message) + 1) {
      return -2; // Ошибка: буфер слишком мал
   }

   // strcpy_s(outputBuffer, bufferSize, message);

   return 0; // Успех
}
