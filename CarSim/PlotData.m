clc, clear, close all;

A = load('track.txt');

subplot(4, 2, 1);
plot(A(:, 1), A(:, 2));
title('Speed');
xlabel('Time in s');
ylabel('Speed in km/h');
grid;

subplot(4, 2, 2);
plot(A(:, 1), A(:, 3));
title('Acceleration');
xlabel('Time in s');
ylabel('Acceleration in m/2²');
grid;

subplot(4, 2, 3);
plot(A(:, 1), A(:, 4));
title('Force');
xlabel('Time in s');
ylabel('Force in N');
grid;

subplot(4, 2, 4);
plot(A(:, 1), A(:, 5));
title('Motor-Torque');
xlabel('Time in s');
ylabel('Torque in Nm');
grid;

subplot(4, 2, 5);
plot(A(:, 1), A(:, 6));
title('Motor-Frequency');
xlabel('Time in s');
ylabel('Frequency in U/min');
grid;

subplot(4, 2, 6);
plot(A(:, 1), A(:, 7));
title('Gas');
xlabel('Time in s');
ylabel('Gas');
grid;

subplot(4, 2, 7);
plot(A(:, 1), A(:, 8));
title('Consumption');
xlabel('Time in s');
ylabel('Consumption');
grid;

subplot(4, 2, 8);
plot(A(:, 1), A(:, 9));
title('Gear');
xlabel('Time in s');
ylabel('Gear');
grid;