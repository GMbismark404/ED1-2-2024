object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 702
  ClientWidth = 923
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object CrearPolinomio: TButton
    Left = 24
    Top = 32
    Width = 113
    Height = 25
    Caption = 'Crear Polinomio'
    TabOrder = 0
    OnClick = CrearPolinomioClick
  end
  object PonerTermino: TButton
    Left = 24
    Top = 72
    Width = 113
    Height = 25
    Caption = 'Poner Termino'
    TabOrder = 1
    OnClick = PonerTerminoClick
  end
  object MostrarPolinomio: TButton
    Left = 24
    Top = 112
    Width = 113
    Height = 25
    Caption = 'Mostrar Polinomio'
    TabOrder = 2
    OnClick = MostrarPolinomioClick
  end
  object Derivar: TButton
    Left = 24
    Top = 152
    Width = 113
    Height = 25
    Caption = 'Derivar'
    TabOrder = 3
    OnClick = DerivarClick
  end
  object Salir: TButton
    Left = 24
    Top = 192
    Width = 113
    Height = 25
    Caption = 'Salir'
    TabOrder = 4
    OnClick = SalirClick
  end
  object Edit1: TEdit
    Left = 151
    Top = 73
    Width = 34
    Height = 23
    TabOrder = 5
    TextHint = 'Coef'
  end
  object Edit2: TEdit
    Left = 191
    Top = 73
    Width = 34
    Height = 23
    TabOrder = 6
    TextHint = 'Exp'
  end
end
