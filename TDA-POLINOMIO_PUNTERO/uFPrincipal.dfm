object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 575
  ClientWidth = 801
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object PonerTermino: TButton
    Left = 16
    Top = 72
    Width = 121
    Height = 25
    Caption = 'Poner Termino'
    TabOrder = 0
    OnClick = PonerTerminoClick
  end
  object MostrarPolinomio: TButton
    Left = 16
    Top = 112
    Width = 121
    Height = 25
    Caption = 'Mostrar Polinomio'
    TabOrder = 1
    OnClick = MostrarPolinomioClick
  end
  object Derivar: TButton
    Left = 16
    Top = 152
    Width = 121
    Height = 25
    Caption = 'Derivar'
    TabOrder = 2
    OnClick = DerivarClick
  end
  object Salir: TButton
    Left = 16
    Top = 192
    Width = 121
    Height = 25
    Caption = 'Salir'
    TabOrder = 3
    OnClick = SalirClick
  end
  object CrearPolinomio: TButton
    Left = 16
    Top = 32
    Width = 121
    Height = 25
    Caption = 'Crear Polinomio'
    TabOrder = 4
    OnClick = CrearPolinomioClick
  end
  object Edit1: TEdit
    Left = 152
    Top = 73
    Width = 41
    Height = 23
    TabOrder = 5
    TextHint = 'Coef'
  end
  object Edit2: TEdit
    Left = 199
    Top = 73
    Width = 41
    Height = 23
    TabOrder = 6
    TextHint = 'Exp'
  end
end
