object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 630
  ClientWidth = 907
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object Button1: TButton
    Left = 8
    Top = 56
    Width = 105
    Height = 25
    Caption = 'Crear Lista'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 103
    Width = 105
    Height = 25
    Caption = 'Insertar Inicio'
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 153
    Width = 105
    Height = 25
    Caption = 'Insertar Final'
    TabOrder = 2
    OnClick = Button3Click
  end
  object Button4: TButton
    Left = 8
    Top = 200
    Width = 105
    Height = 25
    Caption = 'Mostrar Lista'
    TabOrder = 3
    OnClick = Button4Click
  end
  object Edit1: TEdit
    Left = 127
    Top = 104
    Width = 49
    Height = 23
    TabOrder = 4
  end
  object Edit2: TEdit
    Left = 127
    Top = 154
    Width = 49
    Height = 23
    TabOrder = 5
  end
end
