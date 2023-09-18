QGridLayout *gridLayout = new QGridLayout();

// Add widgets to the grid layout at specific positions
QWidget *widget1 = new QPushButton("Button 1");
gridLayout->addWidget(widget1, 0, 0);

QWidget *widget2 = new QLabel("Label");
gridLayout->addWidget(widget2, 0, 1);

QWidget *widget3 = new QLineEdit();
gridLayout->addWidget(widget3, 1, 0);

// Set the layout for the main widget
mainWidget->setLayout(gridLayout);
