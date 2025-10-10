Import("env")
import os
import shutil

# Пути
src_dir = "data" 
build_dir = env.subst("$BUILD_DIR")
target_dir = os.path.join(build_dir, "data")

# Проверка и создание целевой директории
print(f"копирование: {src_dir} -> {target_dir} ...")

# Удаление существующей директории перед копированием
if os.path.exists(target_dir):
    print(f"Удаление существующей директории: {target_dir} ...")
    try:
        shutil.rmtree(target_dir)
        print(f"[SUCCESS] Удалено: {target_dir}")
    except Exception as e:
        print(f"[ERROR] Ошибка удаления: {str(e)}")
        Return()

# Копирование с помощью shutil (надежнее, чем команда copy)
try:
    shutil.copytree(src_dir, target_dir)
    print(f"[SUCCESS] Скопировано: {src_dir} -> {target_dir}")
except Exception as e:
    print(f"[ERROR] Ошибка копирования: {str(e)}")
    Return()

# Добавляем действие в процесс сборки
env.AddPostAction(
    "$PROGPATH",
    env.VerboseAction(
        lambda target, source, env: None,  # Пустая функция, так как копирование уже выполнено
        f"Проверка копирования {target_dir}"
    )
)