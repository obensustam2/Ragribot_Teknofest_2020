
while True:

    x = input("Enter a number: ")

    if not x:  # Boş satır okunduğunda program sonlanıyor.
        break

    try:
        y = float(x)   # Problem çıkarabilecek nokta olan x'in float olmama durumu try bloğu içine alındı.

    except ValueError: # Problem çıkartan Python hata adı. Bu durumda döngünün başına dönülür.
        print("Invalid Number")
        continue
    print(y**2)