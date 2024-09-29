object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 647
  ClientWidth = 1005
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -12
  Font.Name = 'Segoe UI'
  Font.Style = []
  TextHeight = 15
  object CrearConjA: TButton
    Left = 16
    Top = 24
    Width = 113
    Height = 25
    Caption = 'Crear Conjunto A'
    TabOrder = 0
    OnClick = CrearConjAClick
  end
  object CrearConjB: TButton
    Left = 16
    Top = 64
    Width = 113
    Height = 25
    Caption = 'Crear Conjunto B'
    TabOrder = 1
    OnClick = CrearConjBClick
  end
  object CrearConjC: TButton
    Left = 16
    Top = 104
    Width = 113
    Height = 25
    Caption = 'Crear Conjunto C'
    TabOrder = 2
    OnClick = CrearConjCClick
  end
  object InsertarElemento: TButton
    Left = 16
    Top = 144
    Width = 113
    Height = 57
    Caption = 'Insertar Elemento'
    TabOrder = 3
    OnClick = InsertarElementoClick
  end
  object MostrarConjunto: TButton
    Left = 16
    Top = 216
    Width = 113
    Height = 57
    Caption = 'Mostrar Conjunto'
    TabOrder = 4
    OnClick = MostrarConjuntoClick
  end
  object UnirEnC: TButton
    Left = 16
    Top = 288
    Width = 113
    Height = 25
    Caption = 'Unir En C'
    TabOrder = 5
    OnClick = UnirEnCClick
  end
  object IntersectarEnC: TButton
    Left = 16
    Top = 328
    Width = 113
    Height = 25
    Caption = 'Intersectar En C'
    TabOrder = 6
    OnClick = IntersectarEnCClick
  end
  object Salir: TButton
    Left = 16
    Top = 367
    Width = 113
    Height = 25
    Caption = 'Salir'
    TabOrder = 7
    OnClick = SalirClick
  end
  object Edit1: TEdit
    Left = 144
    Top = 149
    Width = 121
    Height = 23
    TabOrder = 8
    TextHint = 'A,B,C'
  end
  object Edit2: TEdit
    Left = 144
    Top = 178
    Width = 121
    Height = 23
    TabOrder = 9
    TextHint = 'elemento'
  end
  object Edit3: TEdit
    Left = 144
    Top = 233
    Width = 121
    Height = 23
    TabOrder = 10
    TextHint = 'A,B,C'
  end
end
