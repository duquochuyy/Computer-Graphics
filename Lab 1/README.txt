HƯỚNG DẪN SỬ DỤNG 

Chương trình đọc dữ liệu đầu vào thông qua file input.txt, mỗi dòng trong file sẽ chứ các tham số cho từng hình (mã hình và các giá trị điều khiển), đảm bảo các dòng phải đủ các giá trị để chương trình có thể thực hiện đúng.

File thực thi phải nằm cùng thư mục với file input.txt để có thể đọc dữ liệu, chỉ cần chạy file thực thi, sẽ xuất hiện màn hình GLUT chứa các hình vẽ, màn hình Console hiển thị thông tin hình vẽ và thời gian vẽ hình đó.

Để hiển thị hình vẽ và thời gian chạy các thuật toán dựa vào hàm do OpenGL cung cấp, mở comment trong file Draw2DObject.cpp để chạy. 


Tham số để vẽ của các Object:
Đường thẳng theo DDA: 
	0 x1 y1 x2 y2
	Trong đó: (x1,y1) là tọa độ điểm đầu, (x2,y2) là tọa độ điểm đầu

Đường thẳng theo Bresenham:
	1 x1 y1 x2 y2
	Trong đó: (x1,y1) là tọa độ điểm đầu, (x2,y2) là tọa độ điểm đầu
Hình tròn theo MidPoint:
	2 xT yT r
	Trong đó: (xT, yT) là tọa độ tâm, r là bán kính
Ellipse theo MidPoint:
	3 xT yT a b
	Trong đó: (xT, yT) là tọa độ tâm, a là 1/2 bán kính trục lớn, b là 1/2 bán kính trục nhỏ
Parabol theo MidPoint:
	4 xT yT p
	Trong đó: (xT, yT) là tọa độ đỉnh, p là khoảng cách từ đỉnh đến tiêu tự
Hyperbol theo MidPoint:
	5 xT yT a b
	Trong đó: (xT, yT) là tạo độ tâm, a là độ dài trục thực, b là độ dài trục ảo