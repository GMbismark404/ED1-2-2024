object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 1000
  ClientWidth = 1800
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Position = poDesigned
  Visible = True
  TextHeight = 13
  object Label1: TLabel
    Left = 287
    Top = 497
    Width = 62
    Height = 13
    Caption = 'INTERVALOS'
  end
  object Label2: TLabel
    Left = 183
    Top = 497
    Width = 7
    Height = 13
    Caption = 'A'
  end
  object Label3: TLabel
    Left = 242
    Top = 498
    Width = 6
    Height = 13
    Caption = 'B'
  end
  object Button1: TButton
    Left = 23
    Top = 295
    Width = 121
    Height = 25
    Caption = 'CREAR MEMORIA'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 53
    Top = 326
    Width = 91
    Height = 25
    Caption = 'PEDIR ESPACIO'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 45
    Top = 357
    Width = 99
    Height = 25
    Caption = 'LIBERAR ESPACIO'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 40
    Top = 547
    Width = 107
    Height = 25
    Caption = 'MOSTRAR MEMORIA'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Button5: TButton
    Left = 53
    Top = 387
    Width = 91
    Height = 25
    Caption = 'PONER DATO'
    TabOrder = 4
    OnClick = Button5Click
  end
  object Edit1: TEdit
    Left = 165
    Top = 328
    Width = 121
    Height = 21
    TabOrder = 5
  end
  object Edit2: TEdit
    Left = 165
    Top = 359
    Width = 121
    Height = 21
    TabOrder = 6
  end
  object Edit3: TEdit
    Left = 176
    Top = 551
    Width = 121
    Height = 21
    TabOrder = 7
    Text = '0'
  end
  object Edit4: TEdit
    Left = 303
    Top = 551
    Width = 121
    Height = 21
    TabOrder = 8
    Text = '11'
  end
  object Edit5: TEdit
    Left = 167
    Top = 389
    Width = 49
    Height = 21
    TabOrder = 9
  end
  object Edit6: TEdit
    Left = 222
    Top = 389
    Width = 121
    Height = 21
    TabOrder = 10
    Text = '->'
  end
  object Edit7: TEdit
    Left = 349
    Top = 389
    Width = 121
    Height = 21
    TabOrder = 11
    Text = '1'
  end
  object Edit8: TEdit
    Left = 143
    Top = 114
    Width = 121
    Height = 21
    TabOrder = 12
    Visible = False
  end
  object Edit9: TEdit
    Left = 143
    Top = 145
    Width = 121
    Height = 21
    TabOrder = 13
    Visible = False
  end
  object Button6: TButton
    Left = 24
    Top = 81
    Width = 105
    Height = 25
    Caption = 'CREAR LISTA'
    TabOrder = 14
    Visible = False
    OnClick = Button6Click
  end
  object Button7: TButton
    Left = 24
    Top = 112
    Width = 113
    Height = 25
    Caption = 'INSERTAR PRIMERO'
    TabOrder = 15
    Visible = False
    OnClick = Button7Click
  end
  object Button8: TButton
    Left = 24
    Top = 143
    Width = 105
    Height = 25
    Caption = 'INSERTAR ULTIMO'
    TabOrder = 16
    Visible = False
    OnClick = Button8Click
  end
  object Button9: TButton
    Left = 24
    Top = 174
    Width = 105
    Height = 25
    Caption = 'MOSTRAR LISTA'
    TabOrder = 17
    Visible = False
    OnClick = Button9Click
  end
  object Button10: TButton
    Left = 288
    Top = 81
    Width = 123
    Height = 25
    Caption = 'Practico'
    TabOrder = 18
    OnClick = Button10Click
  end
  object Button11: TButton
    Left = 40
    Top = 423
    Width = 107
    Height = 25
    Caption = 'CREAR POLIMONIO'
    TabOrder = 19
    OnClick = Button11Click
  end
  object Button12: TButton
    Left = 40
    Top = 454
    Width = 105
    Height = 25
    Caption = 'PONER TERMINO'
    TabOrder = 20
    OnClick = Button12Click
  end
  object Button13: TButton
    Left = 69
    Top = 485
    Width = 75
    Height = 25
    Caption = 'DERIVADA'
    TabOrder = 21
    OnClick = Button13Click
  end
  object Button14: TButton
    Left = 24
    Top = 516
    Width = 123
    Height = 25
    Caption = 'GRAFICAR POLIMONIO'
    TabOrder = 22
    OnClick = Button14Click
  end
  object Edit10: TEdit
    Left = 162
    Top = 456
    Width = 49
    Height = 21
    TabOrder = 23
    Text = '1'
  end
  object Edit11: TEdit
    Left = 232
    Top = 456
    Width = 49
    Height = 21
    TabOrder = 24
    Text = '2'
  end
  object Button15: TButton
    Left = 40
    Top = 232
    Width = 75
    Height = 25
    Caption = 'EVALUAR'
    TabOrder = 25
    Visible = False
    OnClick = Button15Click
  end
  object Edit12: TEdit
    Left = 136
    Top = 234
    Width = 121
    Height = 21
    TabOrder = 26
    Text = 'Edit12'
    Visible = False
  end
  object Edit13: TEdit
    Left = 176
    Top = 518
    Width = 49
    Height = 21
    TabOrder = 27
    Text = '-12'
  end
  object Edit14: TEdit
    Left = 231
    Top = 518
    Width = 50
    Height = 21
    TabOrder = 28
    Text = '12'
  end
  object Button16: TButton
    Left = 40
    Top = 256
    Width = 75
    Height = 25
    Caption = 'Button16'
    TabOrder = 29
    OnClick = Button16Click
  end
  object Edit15: TEdit
    Left = 136
    Top = 258
    Width = 121
    Height = 21
    TabOrder = 30
    Text = 'Edit15'
  end
end
