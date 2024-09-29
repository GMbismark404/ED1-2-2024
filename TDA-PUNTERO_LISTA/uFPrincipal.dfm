object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 718
  ClientWidth = 1023
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object CrearLista: TButton
    Left = 8
    Top = 43
    Width = 105
    Height = 25
    Caption = 'Crear Lista'
    TabOrder = 0
    OnClick = CrearListaClick
  end
  object InsertarInicio: TButton
    Left = 8
    Top = 82
    Width = 105
    Height = 25
    Caption = 'Inserta Inicio'
    TabOrder = 1
    OnClick = InsertarInicioClick
  end
  object InsertarFinal: TButton
    Left = 8
    Top = 121
    Width = 105
    Height = 25
    Caption = 'Inserta Final'
    TabOrder = 2
    OnClick = InsertarFinalClick
  end
  object MostrarLista: TButton
    Left = 8
    Top = 160
    Width = 105
    Height = 25
    Caption = 'Mostrar Lista'
    TabOrder = 3
    OnClick = MostrarListaClick
  end
  object Edit1: TEdit
    Left = 119
    Top = 83
    Width = 58
    Height = 23
    TabOrder = 4
  end
  object Edit2: TEdit
    Left = 119
    Top = 122
    Width = 58
    Height = 23
    TabOrder = 5
  end
end
